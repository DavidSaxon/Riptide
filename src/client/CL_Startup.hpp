/*!
 * \file
 * \author David Saxon
 * \brief Routines relating to the startup of the Riptide Client.
 */
#ifndef RIPTIDE_CLIENT_STARTUP_HPP_
#define RIPTIDE_CLIENT_STARTUP_HPP_

namespace rip_c
{
/*!
 * \brief Startup routines for Scry.
 */
namespace startup
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Performs integral initialisation of Scry.
 *
 * \return Whether initialisation completed successfully.
 */
bool initialisation_routine();

/*!
 * \brief Performs the shutdown of Scry.
 *
 * \return Whether shutdown completed successfully.
 */
bool shutdown_routine();

} // namespace startup
} // namespace rip_c

#endif
