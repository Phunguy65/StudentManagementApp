#ifndef SORTEDMETHODSELECTIONS_H
#define SORTEDMETHODSELECTIONS_H
#include <QQmlEngine>
class SortedMethodSelections
{
    Q_GADGET
  public:
    SortedMethodSelections();

    enum SortedMethod
    {
        InsertionSort,
        SelectionSort,
        BubbleSort,
        QuickSort,
        HeapSort,
        MergeSort,
    };

    Q_ENUM(SortedMethod)
};

#endif // SORTEDMETHODSELECTIONS_H
