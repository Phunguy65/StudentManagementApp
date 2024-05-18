#ifndef STATISTICSCONTROLLER_H
#define STATISTICSCONTROLLER_H

#include "highestscoreslist.h"
#include "highestscoreslistview.h"
#include "lowestscoreslist.h"
#include "lowestscoreslistview.h"
#include <QObject>
#include <QQmlEngine>
#include <memory>
namespace Models
{

class StatisticsController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON
    Q_PROPERTY(Models::HighestScoresListView *highestScoresList READ HighestListView CONSTANT)
    Q_PROPERTY(Models::LowestScoresListView *lowestScoresList READ LowestListView CONSTANT)

    Q_PROPERTY(float averageScore READ AverageScore NOTIFY averageScoreChanged)
    Q_PROPERTY(int totalStudent READ TotalStudent NOTIFY totalStudentChanged)

    Q_PROPERTY(float percentageGoodScore READ PercentageGoodScore NOTIFY distributionScoreChanged)
    Q_PROPERTY(float percentageAverageScore READ PercentageAverageScore NOTIFY distributionScoreChanged)
    Q_PROPERTY(float percentageWeakScore READ PercentageWeakScore NOTIFY distributionScoreChanged)
    Q_PROPERTY(QVariantList distributionScore READ DistributionScore NOTIFY distributionScoreChanged)

  public:
    explicit StatisticsController(QObject *parent = nullptr);

    HighestScoresListView *HighestListView() const;
    LowestScoresListView *LowestListView() const;

    float AverageScore() const;
    int TotalStudent() const;

    QVariantList DistributionScore() const;

    /*Distribution score*/

    /*Percentage distribution score*/

    float PercentageGoodScore() const;
    float PercentageAverageScore() const;
    float PercentageWeakScore() const;
  signals:
    void errorOccurred(const QString &errorMessage);

    /*Signal to update Distribution Score*/
    void distributionScoreChanged();
    void averageScoreChanged();
    void totalStudentChanged();
  public slots:

    void receiveListStudent(const QList<Student> &students);

  private:
    void Init();

    void AddStudentInternal(const Student &student);
    void AddDistributionScore(const int &score);
    void ClearList();
    void ClearDistributionScore();
    void Refresh();

    void CalculateInternal();

    QHash<int, int> _distributionScores;
    std::unique_ptr<Models::HighestScoresList> _highestScoresList;
    std::unique_ptr<Models::LowestScoresList> _lowestScoresList;
    std::unique_ptr<Models::HighestScoresListView> _highestScoresListView;
    std::unique_ptr<Models::LowestScoresListView> _lowestScoresListView;
    QVariantList _listDistributionScore;
};

} // namespace Models

#endif // STATISTICSCONTROLLER_H
