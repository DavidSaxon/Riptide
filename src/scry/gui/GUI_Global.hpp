/*!
 * \file
 * \author David Saxon
 * \brief Global objects for Scry's GUI.
 */
#ifndef RIPTIDE_SCRY_GUI_GLOBAL_HPP_
#define RIPTIDE_SCRY_GUI_GLOBAL_HPP_

#include "scry/util/MetaUtil.hpp"

class QApplication;

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
extern util::meta::DocumentPtr resource_locations;
/*!
 * \brief The MetaEngine Document containing data about fonts.
 */
extern util::meta::DocumentPtr fonts;

} // namespace meta

/*!
 * \brief The Qt application.
 */
extern QApplication* qt_application;

} // namespace global
} // namespace gui
} // namespace scry

#endif
