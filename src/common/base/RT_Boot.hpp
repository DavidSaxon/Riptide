/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Riptide.
 */
#ifndef RIPTIDE_COMMON_BASE_BOOT_HPP_
#define RIPTIDE_COMMON_BASE_BOOT_HPP_

namespace rip
{
/*!
 * \brief Boot up and boot down routines for Riptide commons.
 */
namespace boot
{

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Performs integral initialisation of Riptide commons.
 *
 * \return Whether initialisation completed successfully.
 */
bool initialisation_routine();

/*!
 * \brief Performs the shutdown of Riptide commons.
 *
 * \return Whether shutdown completed successfully.
 */
bool shutdown_routine();

} // namespace boot
} // namespace rip

#endif
