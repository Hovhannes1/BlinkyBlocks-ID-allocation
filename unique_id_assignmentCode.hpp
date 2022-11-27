/**
 * @file unique_id_assignmentCode.hpp
 * Generated by VisibleSim BlockCode Generator
 * https://services-stgi.pu-pm.univ-fcomte.fr/visiblesim/generator.php#
 * @author Hovhannes STEPANYAN
 * @date 17-11-2022
 **/
#ifndef Unique_ID_AssignmentCode_H_
#define Unique_ID_AssignmentCode_H_
#include "robots/blinkyBlocks/blinkyBlocksBlockCode.h"
#include "robots/blinkyBlocks/blinkyBlocksSimulator.h"
#include "robots/blinkyBlocks/blinkyBlocksWorld.h"

static const int GO_MSG_ID = 1001;
static const int BACK_MSG_ID = 1002;
static const int PASS_MSG_ID = 1003;

using namespace BlinkyBlocks;

class Unique_ID_AssignmentCode : public BlinkyBlocksBlockCode {
   private:
    BlinkyBlocksBlock *module = nullptr;
    bool isLeader = false;
    int myDistance;
    int myUniqueID;
    bool isDiscovered = false;
    int numberOfAwaitingReplies = 0;
    int numberOfNodesAfterMe = 0;
    P2PNetworkInterface *parent = nullptr;
    // children saves the children of the current node and the number of nodes each child has after it
    vector<pair<P2PNetworkInterface *, int>> children = {};

   public:
    Unique_ID_AssignmentCode(BlinkyBlocksBlock *host);
    ~Unique_ID_AssignmentCode(){};

    /**
     * This function is called on startup of the blockCode, it can be used to perform initial
     *  configuration of the host or this instance of the program.
     * @note this can be thought of as the main function of the module
     */
    void startup() override;

    /**
     * @brief Message handler for the message 'go'
     * @param _msg Pointer to the message received by the module, requires casting
     * @param sender Connector of the module that has received the message and that is connected to the sender
     */
    void myGoFunc(std::shared_ptr<Message> _msg, P2PNetworkInterface *sender);

    /**
     * @brief Message handler for the message 'back'
     * @param _msg Pointer to the message received by the module, requires casting
     * @param sender Connector of the module that has received the message and that is connected to the sender
     */
    void myBackFunc(std::shared_ptr<Message> _msg, P2PNetworkInterface *sender);

    void messagePassingFunction(std::shared_ptr<Message> _msg, P2PNetworkInterface *sender);

    /**
     * @brief Provides the user with a pointer to the configuration file parser, which can be used to read additional user information from each block config. Has to be overridden in the child class.
     * @param config : pointer to the TiXmlElement representing the block configuration file, all information related to concerned block have already been parsed
     *
     */
    void parseUserBlockElements(TiXmlElement *config) override;

    /*****************************************************************************/
    /** needed to associate code to module                                      **/
    static BlockCode *buildNewBlockCode(BuildingBlock *host) {
        return (new Unique_ID_AssignmentCode((BlinkyBlocksBlock *)host));
    }
    /*****************************************************************************/
};

#endif /* Unique_ID_AssignmentCode_H_ */