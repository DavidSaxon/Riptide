/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Scry's GUI.
 */
#ifndef RIPTIDE_SCRY_GUI_GLOBAL_HPP_
#define RIPTIDE_SCRY_GUI_GLOBAL_HPP_

#include "common/util/MetaUtil.hpp"

namespace scry
{
namespace gui
{
/*!
 * \brief Contains the global objects for Scry's GUI.
 */
namespace global
{

//------------------------------------------------------------------------------
//                                GLOBAL VARIABLES
//------------------------------------------------------------------------------

/*!
 * \brief Common MetaEngine Documents and Variants for Scry's GUI.
 */
namespace meta
{

/*!
 * \brief The MetaEngine Document for the directories where resources are found.
 */
extern rip::util::meta::DocumentPtr resource_locations;
/*!
 * \brief The MetaEngine Document containing data about fonts.
 */
extern rip::util::meta::DocumentPtr fonts;

/*!
 * \brief The MetaEngine Document containing data about startup widgets.
 */
extern rip::util::meta::DocumentPtr widgets_startup;

} // namespace meta

} // namespace global
} // namespace gui
} // namespace scry

#endif
