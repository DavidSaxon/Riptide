/*!
 * \file
 * \author David Saxon
 * \brief Logging for Scry using ArcaneLog.
 */
#ifndef RIPTIDE_SCRY_BASE_LOGGING_HPP_
#define RIPTIDE_SCRY_BASE_LOGGING_HPP_

#include <arcanelog/Input.hpp>
#include <arcanelog/Verbosity.hpp>

#include "core/util/MetaUtil.hpp"

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

namespace arclog
{

class FileOutput;
class StdOutput;

} // namespace arclog


namespace scry
{
/*!
 * \brief Logging components of Scry.
 */
namespace logging
{

//------------------------------------------------------------------------------
//                                    GLOBALS
//------------------------------------------------------------------------------

/*!
 * \brief The logging input to be used by Scry.
 */
extern arclog::Input* input;

} // namespace logging

/*!
 * \brief Convenience reference to the logger.
 *
 * Points to scry::logging::input
 */
extern arclog::Input*& logger;

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
extern rip::util::meta::VariantPtr metadata;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

/*!
 * \brief Initialises the logging from Metaengine data.
 */
void initialisation_routine();

/*!
 * \brief Returns the output stream that should be used to log critical messages
 *        to.
 *
 * This is useful when needing to log critical errors before knowing that
 * logging has been initialised.
 */
std::ostream& get_critical_stream();

//------------------------------------------------------------------------------
//                                    CLASSES
//------------------------------------------------------------------------------

/*!
 * \brief MetaEngine Visitor object used to retrieve arclog::Verbosity values
 *                   from a metaengine::Document.
 *
 * Verbosity values must be expressed in the document as one of the following
 * strings:
 *
 * - critical
 * - error
 * - warning
 * - notice
 * - info
 * - debug
 */
class ArcLogVerbosityV : public metaengine::Visitor<arclog::Verbosity>
{
public:

    /*!
     * \brief Provides an existing static instance of this object.
     */
    static ArcLogVerbosityV& instance();

    // override
    virtual bool retrieve(
            const Json::Value* data,
            const arc::str::UTF8String& key,
            metaengine::Document* requester,
            arc::str::UTF8String& error_message);
};

} // namespace logging
} // namespace scry


#endif
