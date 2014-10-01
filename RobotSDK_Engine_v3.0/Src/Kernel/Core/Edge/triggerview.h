#ifndef TRIGGERVIEW_H
#define TRIGGERVIEW_H

/*! \addtogroup Edge
    @{
*/

/*! \file triggerview.h
    \brief Defines the TriggerView.
    \details View to show processing.
*/

#include<qwidget.h>
#include<qpushbutton.h>
#include<qlayout.h>
#include<qfiledialog.h>
#include<qlabel.h>
#include<qstring.h>
#include<qfile.h>
#include<qpainter.h>
#include<qimage.h>
#include<qlist.h>
#include<qtimer.h>

#include<Core/Node/node.h>

#define MARGIN 10

/*! \struct NodeTriggerPoint
    \brief The struct to save trigger point from node and it's used for painting.
*/
struct NodeTriggerPoint
{
    /*! \var datetime
        \brief The date and time.
    */
    QDateTime datetime;
    /*! \var triggerstate
        \breif The state of the node's trigger.
    */
    Node::NodeTriggerState triggerstate;
};

/*! class TriggerView
    \brief Class TriggerView shows the sequence diagram of node's processing.
*/
class TriggerView : public QWidget
{
    Q_OBJECT
public:
    /*! \fn TriggerView(QWidget *parent, Node * node, int timeRange, int timeInterval, bool gotoThread)
        \breif The constructor of the TriggerView.
        \param [in] parent The parent widget, it is Edge.
        \param [in] node The node to be monitored.
        \param [in] timeRange The range of the time to be monitored.
        \param [in] timeInterval The interval between vertical grid.
        \param [in] gotoThread The flag to show whether the node will be moved to sub-thread.
    */
    TriggerView(QWidget *parent, Node * node, int timeRange, int timeInterval, bool gotoThread);
    /*! \fn ~TriggerView()
        \brief The destructor of the TriggerView.
    */
    ~TriggerView();
protected:
    /*! \var backupnode
        \brief To store the node for disconnection.
    */
    Node * backupnode;
    /*! \var nodetag
        \brief The tag of the node (Type_Class_Name)
    */
    QString nodetag;
    /*! \var timerange
        \brief The time range of the monitor.
    */
    int timerange;
    /*! \var timeinterval
        \brief The interal of the vertical grid.
    */
    int timeinterval;
protected:
    /*! \var pulse
        \brief The label to show the image.
    */
    QLabel pulse;
    /*! \var triggerlist
        \brief The list of NodeTriggerPoint for painting.
    */
    QList<NodeTriggerPoint> triggerlist;
public:
    /*! \fn void setTimeLine(int timeRange, int timeInterval)
        \brief To set monitor's time line \ref timerange and \ref timeinterval.
    */
    void setTimeLine(int timeRange, int timeInterval);
public slots:
    /*! \fn void nodeTriggerTimeSlot(QDateTime curDateTime, Node::NodeTriggerState nodeTriggerState)
        \brief Slot function to receive trigger signal from Node.
        \param [in] curDateTime Current Date and Time.
        \param [in] nodeTriggerState The state of the node's trigger.
    */
    void nodeTriggerTimeSlot(QDateTime curDateTime, Node::NodeTriggerState nodeTriggerState);
public slots:
    /*! \fn void drawSlot(QDateTime curDateTime)
        \brief Slot function to draw monitor.
        \param [in] curDateTime Current date and time.
    */
    void drawSlot(QDateTime curDateTime);
};

#endif // TRIGGERVIEW_H
