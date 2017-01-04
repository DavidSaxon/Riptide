/*!
 * \file
 * \author David Saxon
 */
#ifndef RIPTIDE_SCRY_CLIENT_HPP_
#define RIPTIDE_SCRY_CLIENT_HPP_

#include <arcanecore/base/Preproc.hpp>

namespace scry
{

/*!
 * \brief The singleton root object that manages the runtime of the Riptide
 *        client.
 *
 * This object takes control once execute is called, and only leaves the execute
 * function after shutdown, or if a critical error has occurred.
 */
class Client
{
public:

    ARC_DISALLOW_COPY_AND_ASSIGN(Client);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Client();

    //--------------------------------------------------------------------------
    //                          PUBLIC STATIC FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Returns the singleton instance of the Riptide Client.
     */
    static Client* get_instance();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Begins execution of the Client.
     *
     * Control is only returned from this function once the Client is
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
     * \brief Constructs a new instance of the Client.
     */
    Client();
};

} // namespace scry

#endif
