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
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Signifies whether the Riptide Client has been initialised.
     */
    bool m_initialised;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTORS
    //--------------------------------------------------------------------------

    /*!
     * \brief Constructs a new instance of the RiptideClient.
     */
    RiptideClient();

    //--------------------------------------------------------------------------
    //                          PRIVATE MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Runs the initialisation routines of the Riptide Client.
     *
     * The initialisation routines are the first integral parts of the Riptide
     * Client to be started.
     *
     * \returns Whether the initialisation routines completed successfully.
     */
    bool run_initialisation_routines();
};

} // namespace rip_c

#endif
