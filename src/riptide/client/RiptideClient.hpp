#ifndef RIPTIDE_CLIENT_RIPTIDECLIENT_HPP_
#define RIPTIDE_CLIENT_RIPTIDECLIENT_HPP_

#include <arcanecore/base/Preproc.hpp>

namespace rip
{
namespace client
{

/*!
 * \brief The root object that manages the runtime of the Riptide client.
 *
 * This object takes control once execute is called, and only leaves the execute
 * function after shutdown, or if a critical error has occurred.
 */
class RiptideClient
{
public:

    ARC_DISALLOW_COPY_AND_ASSIGN(RiptideClient);

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Constructs a new instance of the RiptideClient.
     */
    RiptideClient();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RiptideClient();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Begins execution of the RiptideClient.
     *
     * Control is only returned from this function once the RiptideClient is
     * exited, or a critical error is encountered.
     *
     * \return The error status of execution (0 if the client exited
     *         successfully)
     */
    int execute();
};

} // namespace client
} // namespace rip

#endif
