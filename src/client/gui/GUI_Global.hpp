/*!
 * \file
 * \author David Saxon
 * \brief Global objects for the Riptide Client's GUI.
 */
#ifndef RIPTIDE_CLIENT_GUI_GLOBAL_HPP_
#define RIPTIDE_CLIENT_GUI_GLOBAL_HPP_

#include "client/util/MetaUtil.hpp"

class QApplication;

namespace rip_c
{
namespace gui
{
/*!
 * \brief Contains the global objects for the Riptide Client's GUI.
 */
namespace global
{

//------------------------------------------------------------------------------
//                                GLOBAL VARIABLES
//------------------------------------------------------------------------------

/*!
 * \brief Common MetaEngine Documents and Variants for the Riptide Client's GUI.
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
} // namespace rip_c

#endif
