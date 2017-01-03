/*!
 * \file
 * \author David Saxon
 */
#ifndef RIPTIDE_CLIENT_RIPTIDECLIENT_HPP_
#define RIPTIDE_CLIENT_RIPTIDECLIENT_HPP_

#include <arcanecore/base/Preproc.hpp>

namespace rip_c
{

/*!
 * \brief The singleton root object that manages the runtime of the Riptide
 *        client.
 *
 * This object takes control once execute is called, and only leaves the execute
 * function after shutdown, or if a critical error has occurred.
 */
class RiptideClient
{
public:

    ARC_DISALLOW_COPY_AND_ASSIGN(RiptideClient);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~RiptideClient();

    //--------------------------------------------------------------------------
    //                          PUBLIC STATIC FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Returns the singleton instance of the Riptide Client.
     */
    static RiptideClient* get_instance();

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

private:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Constructs a new instance of the RiptideClient.
     */
    RiptideClient();
};

} // namespace rip_c

#endif
