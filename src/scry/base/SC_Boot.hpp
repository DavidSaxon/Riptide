/*!
 * \file
 * \author David Saxon
 * \brief Routines relating to the boot up and boot down of Scry.
 */
#ifndef RIPTIDE_SCRY_BASE_BOOT_HPP_
#define RIPTIDE_SCRY_BASE_BOOT_HPP_

namespace scry
{
/*!
 * \brief Boot up and boot down routines for Scry.
 */
namespace boot
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

} // namespace boot
} // namespace scry

#endif
