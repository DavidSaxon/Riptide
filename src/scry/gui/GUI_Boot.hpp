/*!
 * \file
 * \author David Saxon
 * \brief Routines relating to the boot up and boot down of Scry's GUI.
 */
#ifndef RIPTIDE_SCRY_GUI_BOOT_HPP_
#define RIPTIDE_SCRY_GUI_BOOT_HPP_

namespace scry
{
namespace gui
{
/*!
 * \brief Boot up and boot down routines for Scry's GUI.
 */
namespace boot
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Performs the integral initialisation of Scry's GUI.
 */
void initialisation_routine();

/*!
 * \brief Performs shutdown of Scry's GUI.
 */
void shutdown_routine();

} // namespace boot
} // namespace gui
} // namespace scry

#endif
