/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Riptide.
 */
#ifndef RIPTIDE_CORE_BASE_BOOT_HPP_
#define RIPTIDE_CORE_BASE_BOOT_HPP_

namespace rip
{
/*!
 * \brief Boot up and boot down routines for the Riptide core.
 */
namespace boot
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Performs integral initialisation of the Riptide core.
 *
 * \return Whether initialisation completed successfully.
 */
bool initialisation_routine();

/*!
 * \brief Performs the shutdown of the Riptide core.
 *
 * \return Whether shutdown completed successfully.
 */
bool shutdown_routine();

} // namespace boot
} // namespace rip

#endif
