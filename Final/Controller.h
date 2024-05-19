// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef __FINAL_CONTROLLER_H_
#define __FINAL_CONTROLLER_H_

#include <omnetpp.h>
#include <Node.h>

using namespace omnetpp;

/**
 * TODO - Generated class
 */
class Controller : public cSimpleModule
{

  protected:
    int totalNodes;
    std::vector<Node*> nodes;

    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

#endif
