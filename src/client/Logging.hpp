/*!
 * \file
 * \author David Saxon
 * \brief Logging for the Riptide Client using ArcaneLog.
 */
#ifndef RIPTIDE_CLIENT_LOGGING_HPP_
#define RIPTIDE_CLIENT_LOGGING_HPP_

#include <arcanelog/Verbosity.hpp>

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace arclog
{

class FileOutput;
class Input;
class StdOutput;

} // namespace arclog


namespace rip_c
{
/*!
 * \brief Logging components of the Riptide Client.
 */
namespace logging
{

//------------------------------------------------------------------------------
//                                    GLOBALS
//------------------------------------------------------------------------------

/*!
 * \brief The logging input to be used by the Riptide Client.
 */
extern arclog::Input* input;

} // namespace logging

/*!
 * \brief Special case reference for convenience that points to
 *        rip::rip_c::logging::input
 */
extern arclog::Input& logger;

namespace logging
{

/*!
 * \brief The logging output to std::cout and std::cerr.
 */
extern arclog::StdOutput* std_output;
/*!
 * \brief The logging output for writing to the file system.
 */
extern arclog::FileOutput* file_output;

/*!
 * \brief The MetaEngine Variant for logging configuration.
 */
extern util::meta::VariantPtr metadata;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Initialises the logging from Metaengine data.
 */
void initialisation_routine();

//------------------------------------------------------------------------------
//                                    CLASSES
//------------------------------------------------------------------------------

// TODO: verbosity visitor

} // namespace logging
} // namespace rip_c


#endif
