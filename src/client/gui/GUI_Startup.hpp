/*!
 * \file
 * \author David Saxon
 * \brief Routines relating to the startup of the Riptide Client's GUI.
 */
#ifndef RIPTIDE_CLIENT_GUI_STARTUP_HPP_
#define RIPTIDE_CLIENT_GUI_STARTUP_HPP_

namespace rip_c
{
namespace gui
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Performs the integral initialisation of the Riptide Client's GUI.
 */
void initialisation_routine();

/*!
 * \brief Performs shutdown of the Riptide Client's GUI.
 */
void shutdown_routine();

} // namespace gui
} // namespace rip_c

#endif
