#include "statisticscontroller.h"
#include "studentvalidator.h"
#include <QHash>
#include <QString>
namespace Models
{

StatisticsController::StatisticsController(QObject *parent) : QObject{parent}
{
    _highestScoresList = std::make_unique<Models::HighestScoresList>(this);
    _lowestScoresList = std::make_unique<Models::LowestScoresList>(this);

    _highestScoresListView = std::make_unique<Models::HighestScoresListView>(this);
    _lowestScoresListView = std::make_unique<Models::LowestScoresListView>(this);
    Init();
}

HighestScoresListView *StatisticsController::HighestListView() const
{
    return _highestScoresListView.get();
}

LowestScoresListView *StatisticsController::LowestListView() const
{
    return _lowestScoresListView.get();
}

float StatisticsController::AverageScore() const
{
    float averageScore = 0;

    for (auto [key, value] : _distributionScores.asKeyValueRange())
    {
        averageScore += key * value;
    }

    return averageScore / TotalStudent();
}

int StatisticsController::TotalStudent() const
{
    return _highestScoresList->rowCount();
}

QVariantList StatisticsController::DistributionScore() const
{
    return _listDistributionScore;
}

float StatisticsController::PercentageGoodScore() const
{
    return (_distributionScores[8] + _distributionScores[9] + _distributionScores[10]) * 100.0 / TotalStudent();
}

float StatisticsController::PercentageAverageScore() const
{
    return (_distributionScores[5] + _distributionScores[6] + _distributionScores[7]) * 100.0 / TotalStudent();
}

float StatisticsController::PercentageWeakScore() const
{
    return static_cast<float>(100 - PercentageGoodScore() - PercentageAverageScore());
}

void StatisticsController::AddStudentInternal(const Student &student)
{
    try
    {
        if (Commons::StudentValidator::ValidateStudent(student))
        {
            this->_highestScoresList->insertRow(_highestScoresList->rowCount());
            this->_lowestScoresList->insertRow(_lowestScoresList->rowCount());

            QModelIndex indexHighest = this->_highestScoresList->index(_highestScoresList->rowCount() - 1);
            QModelIndex indexLowest = this->_lowestScoresList->index(_lowestScoresList->rowCount() - 1);

            for (auto const &[key, value] : _highestScoresList->roleNames().asKeyValueRange())
            {
                switch (key)
                {
                case HighestScoresList::IdStudentRole: {
                    this->_highestScoresList->setData(indexHighest, student.GetIdStudent(), key);
                    this->_lowestScoresList->setData(indexLowest, student.GetIdStudent(), key);
                    break;
                }
                case HighestScoresList::LastNameRole: {
                    this->_highestScoresList->setData(indexHighest, student.GetLastName(), key);
                    this->_lowestScoresList->setData(indexLowest, student.GetLastName(), key);
                    break;
                }
                case HighestScoresList::FirstNameRole: {
                    this->_highestScoresList->setData(indexHighest, student.GetFirstName(), key);
                    this->_lowestScoresList->setData(indexLowest, student.GetFirstName(), key);
                    break;
                }
                case HighestScoresList::IdClassRole: {
                    this->_highestScoresList->setData(indexHighest, student.GetIdClass(), key);
                    this->_lowestScoresList->setData(indexLowest, student.GetIdClass(), key);
                    break;
                }
                case HighestScoresList::ScoreRole: {
                    this->_highestScoresList->setData(indexHighest, student.GetScore(), key);
                    this->_lowestScoresList->setData(indexLowest, student.GetScore(), key);
                    break;
                }
                default:
                    break;
                }
            }
        }
    }
    catch (std::exception &e)
    {
        emit errorOccurred(e.what());
    }
}

void StatisticsController::AddDistributionScore(const int &score)
{
    if (score < 0 || score > 10)
    {
        return;
    }

    if (_distributionScores.contains(score))
    {
        _distributionScores[score]++;
    }
    else
    {
        _distributionScores.insert(score, 1);
    }
}

void StatisticsController::ClearList()
{
    try
    {

        this->_highestScoresList->removeRows(0, this->_highestScoresList->rowCount());

        this->_lowestScoresList->removeRows(0, this->_lowestScoresList->rowCount());
    }
    catch (...)
    {
        emit errorOccurred("Error occurred when clear list students");
    }
}

void StatisticsController::ClearDistributionScore()
{
    for (auto it = _distributionScores.begin(); it != _distributionScores.end(); ++it)
    {
        it.value() = 0;
    }
    _listDistributionScore.clear();
}

void StatisticsController::Refresh()
{
    ClearList();
    ClearDistributionScore();
}

void StatisticsController::CalculateInternal()
{
    /* Sort list students */
    _highestScoresList->sort(0, Qt::DescendingOrder);
    _lowestScoresList->sort(0, Qt::AscendingOrder);

    for (auto i = 0; i <= 10; i++)
    {
        _listDistributionScore.append(_distributionScores[i]);
    }

    emit averageScoreChanged();
    emit totalStudentChanged();
    emit distributionScoreChanged();
}

void StatisticsController::receiveListStudent(const QList<Student> &students)
{
    Refresh();

    for (const auto &student : students)
    {
        AddStudentInternal(student);
        AddDistributionScore(student.GetScore().toInt());
    }
    CalculateInternal();
}

void StatisticsController::Init()
{
    this->_highestScoresListView->setSourceModel(_highestScoresList.get());
    this->_lowestScoresListView->setSourceModel(_lowestScoresList.get());

    for (int i = 0; i <= 10; i++)
    {
        _distributionScores.insert(i, 0);
    }
}
} // namespace Models
