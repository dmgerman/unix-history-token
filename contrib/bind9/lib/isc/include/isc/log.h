begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: log.h,v 1.59 2009/02/16 02:01:16 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_LOG_H
value|1
end_define

begin_comment
comment|/*! \file isc/log.h */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_comment
comment|/* XXXDCL NT */
end_comment

begin_include
include|#
directive|include
file|<isc/formatcheck.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * \brief Severity levels, patterned after Unix's syslog levels.  *  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOG_DEBUG
parameter_list|(
name|level
parameter_list|)
value|(level)
end_define

begin_comment
comment|/*!  * #ISC_LOG_DYNAMIC can only be used for defining channels with  * isc_log_createchannel(), not to specify a level in isc_log_write().  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOG_DYNAMIC
value|0
end_define

begin_define
define|#
directive|define
name|ISC_LOG_INFO
value|(-1)
end_define

begin_define
define|#
directive|define
name|ISC_LOG_NOTICE
value|(-2)
end_define

begin_define
define|#
directive|define
name|ISC_LOG_WARNING
value|(-3)
end_define

begin_define
define|#
directive|define
name|ISC_LOG_ERROR
value|(-4)
end_define

begin_define
define|#
directive|define
name|ISC_LOG_CRITICAL
value|(-5)
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * \brief Destinations.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOG_TONULL
value|1
end_define

begin_define
define|#
directive|define
name|ISC_LOG_TOSYSLOG
value|2
end_define

begin_define
define|#
directive|define
name|ISC_LOG_TOFILE
value|3
end_define

begin_define
define|#
directive|define
name|ISC_LOG_TOFILEDESC
value|4
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*%  * Channel flags.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOG_PRINTTIME
value|0x0001
end_define

begin_define
define|#
directive|define
name|ISC_LOG_PRINTLEVEL
value|0x0002
end_define

begin_define
define|#
directive|define
name|ISC_LOG_PRINTCATEGORY
value|0x0004
end_define

begin_define
define|#
directive|define
name|ISC_LOG_PRINTMODULE
value|0x0008
end_define

begin_define
define|#
directive|define
name|ISC_LOG_PRINTTAG
value|0x0010
end_define

begin_define
define|#
directive|define
name|ISC_LOG_PRINTALL
value|0x001F
end_define

begin_define
define|#
directive|define
name|ISC_LOG_DEBUGONLY
value|0x1000
end_define

begin_define
define|#
directive|define
name|ISC_LOG_OPENERR
value|0x8000
end_define

begin_comment
comment|/* internal */
end_comment

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*!  * \brief Other options.  *  * XXXDCL INFINITE doesn't yet work.  Arguably it isn't needed, but  *   since I am intend to make large number of versions work efficiently,  *   INFINITE is going to be trivial to add to that.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOG_ROLLINFINITE
value|(-1)
end_define

begin_define
define|#
directive|define
name|ISC_LOG_ROLLNEVER
value|(-2)
end_define

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*!  * \brief Used to name the categories used by a library.  *  * An array of isc_logcategory  * structures names each category, and the id value is initialized by calling  * isc_log_registercategories.  */
end_comment

begin_struct
struct|struct
name|isc_logcategory
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*%  * Similar to isc_logcategory, but for all the modules a library defines.  */
end_comment

begin_struct
struct|struct
name|isc_logmodule
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|int
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*%  * The isc_logfile structure is initialized as part of an isc_logdestination  * before calling isc_log_createchannel().  *  * When defining an #ISC_LOG_TOFILE  * channel the name, versions and maximum_size should be set before calling  * isc_log_createchannel().  To define an #ISC_LOG_TOFILEDESC channel set only  * the stream before the call.  *  * Setting maximum_size to zero implies no maximum.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_logfile
block|{
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/*%< Initialized to NULL for #ISC_LOG_TOFILE. */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/*%< NULL for #ISC_LOG_TOFILEDESC. */
name|int
name|versions
decl_stmt|;
comment|/*>= 0, #ISC_LOG_ROLLNEVER, #ISC_LOG_ROLLINFINITE. */
comment|/*% 	 * stdio's ftell is standardized to return a long, which may well not 	 * be big enough for the largest file supportable by the operating 	 * system (though it is _probably_ big enough for the largest log 	 * anyone would want).  st_size returned by fstat should be typedef'd 	 * to a size large enough for the largest possible file on a system. 	 */
name|isc_offset_t
name|maximum_size
decl_stmt|;
name|isc_boolean_t
name|maximum_reached
decl_stmt|;
comment|/*%< Private. */
block|}
name|isc_logfile_t
typedef|;
end_typedef

begin_comment
comment|/*%  * Passed to isc_log_createchannel to define the attributes of either  * a stdio or a syslog log.  */
end_comment

begin_typedef
typedef|typedef
union|union
name|isc_logdestination
block|{
name|isc_logfile_t
name|file
decl_stmt|;
name|int
name|facility
decl_stmt|;
comment|/* XXXDCL NT */
block|}
name|isc_logdestination_t
typedef|;
end_typedef

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*%  * The built-in categories of libisc.  *  * Each library registering categories should provide library_LOGCATEGORY_name  * definitions with indexes into its isc_logcategory structure corresponding to  * the order of the names.  */
end_comment

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|isc_logcategory_t
name|isc_categories
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|isc_log_t
modifier|*
name|isc_lctx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|LIBISC_EXTERNAL_DATA
specifier|extern
name|isc_logmodule_t
name|isc_modules
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*@}*/
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/*%  * Do not log directly to DEFAULT.  Use another category.  When in doubt,  * use GENERAL.  */
end_comment

begin_define
define|#
directive|define
name|ISC_LOGCATEGORY_DEFAULT
value|(&isc_categories[0])
end_define

begin_define
define|#
directive|define
name|ISC_LOGCATEGORY_GENERAL
value|(&isc_categories[1])
end_define

begin_comment
comment|/*@}*/
end_comment

begin_define
define|#
directive|define
name|ISC_LOGMODULE_SOCKET
value|(&isc_modules[0])
end_define

begin_define
define|#
directive|define
name|ISC_LOGMODULE_TIME
value|(&isc_modules[1])
end_define

begin_define
define|#
directive|define
name|ISC_LOGMODULE_INTERFACE
value|(&isc_modules[2])
end_define

begin_define
define|#
directive|define
name|ISC_LOGMODULE_TIMER
value|(&isc_modules[3])
end_define

begin_define
define|#
directive|define
name|ISC_LOGMODULE_FILE
value|(&isc_modules[4])
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_log_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_log_t
modifier|*
modifier|*
name|lctxp
parameter_list|,
name|isc_logconfig_t
modifier|*
modifier|*
name|lcfgp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Establish a new logging context, with default channels.  *  * Notes:  *\li	isc_log_create() calls isc_logconfig_create(), so see its comment  *	below for more information.  *  * Requires:  *\li	mctx is a valid memory context.  *\li	lctxp is not null and *lctxp is null.  *\li	lcfgp is null or lcfgp is not null and *lcfgp is null.  *  * Ensures:  *\li	*lctxp will point to a valid logging context if all of the necessary  *	memory was allocated, or NULL otherwise.  *\li	*lcfgp will point to a valid logging configuration if all of the  *	necessary memory was allocated, or NULL otherwise.  *\li	On failure, no additional memory is allocated.  *  * Returns:  *\li	#ISC_R_SUCCESS		Success  *\li	#ISC_R_NOMEMORY		Resource limit: Out of memory  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_logconfig_create
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logconfig_t
modifier|*
modifier|*
name|lcfgp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create the data structure that holds all of the configurable information  * about where messages are actually supposed to be sent -- the information  * that could changed based on some configuration file, as opposed to the  * the category/module specification of isc_log_[v]write[1] that is compiled  * into a program, or the debug_level which is dynamic state information.  *  * Notes:  *\li	It is necessary to specify the logging context the configuration  * 	will be used with because the number of categories and modules  *	needs to be known in order to set the configuration.  However,  *	the configuration is not used by the logging context until the  *	isc_logconfig_use function is called.  *  *\li	The memory context used for operations that allocate memory for  *	the configuration is that of the logging context, as specified  *	in the isc_log_create call.  *  *\li	Four default channels are established:  *\verbatim  *	    	default_syslog  *		 - log to syslog's daemon facility #ISC_LOG_INFO or higher  *		default_stderr  *		 - log to stderr #ISC_LOG_INFO or higher  *		default_debug  *		 - log to stderr #ISC_LOG_DEBUG dynamically  *		null  *		 - log nothing  *\endverbatim  *  * Requires:  *\li 	lctx is a valid logging context.  *\li	lcftp is not null and *lcfgp is null.  *  * Ensures:  *\li	*lcfgp will point to a valid logging context if all of the necessary  *	memory was allocated, or NULL otherwise.  *\li	On failure, no additional memory is allocated.  *  * Returns:  *\li	#ISC_R_SUCCESS		Success  *\li	#ISC_R_NOMEMORY		Resource limit: Out of memory  */
end_comment

begin_function_decl
name|isc_logconfig_t
modifier|*
name|isc_logconfig_get
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns a pointer to the configuration currently in use by the log context.  *  * Requires:  *\li	lctx is a valid context.  *  * Ensures:  *\li	The configuration pointer is non-null.  *  * Returns:  *\li	The configuration pointer.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_logconfig_use
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a new configuration with a logging context.  *  * Notes:  *\li	This is thread safe.  The logging context will lock a mutex  *	before attempting to swap in the new configuration, and isc_log_doit  *	(the internal function used by all of isc_log_[v]write[1]) locks  *	the same lock for the duration of its use of the configuration.  *  * Requires:  *\li	lctx is a valid logging context.  *\li	lcfg is a valid logging configuration.  *\li	lctx is the same configuration given to isc_logconfig_create  *		when the configuration was created.  *  * Ensures:  *\li	Future calls to isc_log_write will use the new configuration.  *  * Returns:  *\li	#ISC_R_SUCCESS		Success  *\li	#ISC_R_NOMEMORY		Resource limit: Out of memory  */
end_comment

begin_function_decl
name|void
name|isc_log_destroy
parameter_list|(
name|isc_log_t
modifier|*
modifier|*
name|lctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Deallocate the memory associated with a logging context.  *  * Requires:  *\li	*lctx is a valid logging context.  *  * Ensures:  *\li	All of the memory associated with the logging context is returned  *	to the free memory pool.  *  *\li	Any open files are closed.  *  *\li	The logging context is marked as invalid.  */
end_comment

begin_function_decl
name|void
name|isc_logconfig_destroy
parameter_list|(
name|isc_logconfig_t
modifier|*
modifier|*
name|lcfgp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a logging configuration.  *  * Notes:  *\li	This function cannot be used directly with the return value of  *	isc_logconfig_get, because a logging context must always have  *	a valid configuration associated with it.  *  * Requires:  *\li	lcfgp is not null and *lcfgp is a valid logging configuration.  *\li	The logging configuration is not in use by an existing logging context.  *  * Ensures:  *\li	All memory allocated for the configuration is freed.  *  *\li	The configuration is marked as invalid.  */
end_comment

begin_function_decl
name|void
name|isc_log_registercategories
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
name|categories
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Identify logging categories a library will use.  *  * Notes:  *\li	A category should only be registered once, but no mechanism enforces  *	this rule.  *  *\li	The end of the categories array is identified by a NULL name.  *  *\li	Because the name is used by #ISC_LOG_PRINTCATEGORY, it should not  *	be altered or destroyed after isc_log_registercategories().  *  *\li	Because each element of the categories array is used by  *	isc_log_categorybyname, it should not be altered or destroyed  *	after registration.  *  *\li	The value of the id integer in each structure is overwritten  *	by this function, and so id need not be initialized to any particular  *	value prior to the function call.  *  *\li	A subsequent call to isc_log_registercategories with the same  *	logging context (but new categories) will cause the last  *	element of the categories array from the prior call to have  *	its "name" member changed from NULL to point to the new  *	categories array, and its "id" member set to UINT_MAX.  *  * Requires:  *\li	lctx is a valid logging context.  *\li	categories != NULL.  *\li	categories[0].name != NULL.  *  * Ensures:  * \li	There are references to each category in the logging context,  * 	so they can be used with isc_log_usechannel() and isc_log_write().  */
end_comment

begin_function_decl
name|void
name|isc_log_registermodules
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logmodule_t
name|modules
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Identify logging categories a library will use.  *  * Notes:  *\li	A module should only be registered once, but no mechanism enforces  *	this rule.  *  *\li	The end of the modules array is identified by a NULL name.  *  *\li	Because the name is used by #ISC_LOG_PRINTMODULE, it should not  *	be altered or destroyed after isc_log_registermodules().  *  *\li	Because each element of the modules array is used by  *	isc_log_modulebyname, it should not be altered or destroyed  *	after registration.  *  *\li	The value of the id integer in each structure is overwritten  *	by this function, and so id need not be initialized to any particular  *	value prior to the function call.  *  *\li	A subsequent call to isc_log_registermodules with the same  *	logging context (but new modules) will cause the last  *	element of the modules array from the prior call to have  *	its "name" member changed from NULL to point to the new  *	modules array, and its "id" member set to UINT_MAX.  *  * Requires:  *\li	lctx is a valid logging context.  *\li	modules != NULL.  *\li	modules[0].name != NULL;  *  * Ensures:  *\li	Each module has a reference in the logging context, so they can be  *	used with isc_log_usechannel() and isc_log_write().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_log_createchannel
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|type
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|isc_logdestination_t
modifier|*
name|destination
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Specify the parameters of a logging channel.  *  * Notes:  *\li	The name argument is copied to memory in the logging context, so  *	it can be altered or destroyed after isc_log_createchannel().  *  *\li	Defining a very large number of channels will have a performance  *	impact on isc_log_usechannel(), since the names are searched  *	linearly until a match is made.  This same issue does not affect  *	isc_log_write, however.  *  *\li	Channel names can be redefined; this is primarily useful for programs  *	that want their own definition of default_syslog, default_debug  *	and default_stderr.  *  *\li	Any channel that is redefined will not affect logging that was  *	already directed to its original definition, _except_ for the  *	default_stderr channel.  This case is handled specially so that  *	the default logging category can be changed by redefining  *	default_stderr.  (XXXDCL Though now that I think of it, the default  *	logging category can be changed with only one additional function  *	call by defining a new channel and then calling isc_log_usechannel()  *	for #ISC_LOGCATEGORY_DEFAULT.)  *  *\li	Specifying #ISC_LOG_PRINTTIME or #ISC_LOG_PRINTTAG for syslog is allowed,  *	but probably not what you wanted to do.  *  *	#ISC_LOG_DEBUGONLY will mark the channel as usable only when the  *	debug level of the logging context (see isc_log_setdebuglevel)  *	is non-zero.  *  * Requires:  *\li	lcfg is a valid logging configuration.  *  *\li	name is not NULL.  *  *\li	type is #ISC_LOG_TOSYSLOG, #ISC_LOG_TOFILE, #ISC_LOG_TOFILEDESC or  *		#ISC_LOG_TONULL.  *  *\li	destination is not NULL unless type is #ISC_LOG_TONULL.  *  *\li	level is>= #ISC_LOG_CRITICAL (the most negative logging level).  *  *\li	flags does not include any bits aside from the ISC_LOG_PRINT* bits  *	or #ISC_LOG_DEBUGONLY.  *  * Ensures:  *\li	#ISC_R_SUCCESS  *		A channel with the given name is usable with  *		isc_log_usechannel().  *  *\li	#ISC_R_NOMEMORY or #ISC_R_UNEXPECTED  *		No additional memory is being used by the logging context.  *		Any channel that previously existed with the given name  *		is not redefined.  *  * Returns:  *\li	#ISC_R_SUCCESS		Success  *\li	#ISC_R_NOMEMORY		Resource limit: Out of memory  *\li	#ISC_R_UNEXPECTED	type was out of range and REQUIRE()  *					was disabled.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_log_usechannel
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
specifier|const
name|isc_logmodule_t
modifier|*
name|module
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Associate a named logging channel with a category and module that  * will use it.  *  * Notes:  *\li	The name is searched for linearly in the set of known channel names  *	until a match is found.  (Note the performance impact of a very large  *	number of named channels.)  When multiple channels of the same  *	name are defined, the most recent definition is found.  *  *\li	Specifying a very large number of channels for a category will have  *	a moderate impact on performance in isc_log_write(), as each  *	call looks up the category for the start of a linked list, which  *	it follows all the way to the end to find matching modules.  The  *	test for matching modules is  integral, though.  *  *\li	If category is NULL, then the channel is associated with the indicated  *	module for all known categories (including the "default" category).  *  *\li	If module is NULL, then the channel is associated with every module  *	that uses that category.  *  *\li	Passing both category and module as NULL would make every log message  *	use the indicated channel.  *  * \li	Specifying a channel that is #ISC_LOG_TONULL for a category/module pair  *	has no effect on any other channels associated with that pair,  *	regardless of ordering.  Thus you cannot use it to "mask out" one  *	category/module pair when you have specified some other channel that  * 	is also used by that category/module pair.  *  * Requires:  *\li	lcfg is a valid logging configuration.  *  *\li	category is NULL or has an id that is in the range of known ids.  *  *	module is NULL or has an id that is in the range of known ids.  *  * Ensures:  *\li	#ISC_R_SUCCESS  *		The channel will be used by the indicated category/module  *		arguments.  *  *\li	#ISC_R_NOMEMORY  *		If assignment for a specific category has been requested,  *		the channel has not been associated with the indicated  *		category/module arguments and no additional memory is  *		used by the logging context.  *		If assignment for all categories has been requested  *		then _some_ may have succeeded (starting with category  *		"default" and progressing through the order of categories  *		passed to isc_log_registercategories()) and additional memory  *		is being used by whatever assignments succeeded.  *  * Returns:  *\li	#ISC_R_SUCCESS	Success  *\li	#ISC_R_NOMEMORY	Resource limit: Out of memory  */
end_comment

begin_comment
comment|/* Attention: next four comments PRECEED code */
end_comment

begin_comment
comment|/*!  *   \brief  * Write a message to the log channels.  *  * Notes:  *\li	Log messages containing natural language text should be logged with  *	isc_log_iwrite() to allow for localization.  *  *\li	lctx can be NULL; this is allowed so that programs which use  *	libraries that use the ISC logging system are not required to  *	also use it.  *  *\li	The format argument is a printf(3) string, with additional arguments  *	as necessary.  *  * Requires:  *\li	lctx is a valid logging context.  *  *\li	The category and module arguments must have ids that are in the  *	range of known ids, as established by isc_log_registercategories()  *	and isc_log_registermodules().  *  *\li	level != #ISC_LOG_DYNAMIC.  ISC_LOG_DYNAMIC is used only to define  *	channels, and explicit debugging level must be identified for  *	isc_log_write() via ISC_LOG_DEBUG(level).  *  *\li	format != NULL.  *  * Ensures:  *\li	The log message is written to every channel associated with the  *	indicated category/module pair.  *  * Returns:  *\li	Nothing.  Failure to log a message is not construed as a  *	meaningful error.  */
end_comment

begin_function_decl
name|void
name|isc_log_write
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%  * Write a message to the log channels.  *  * Notes:  *\li	lctx can be NULL; this is allowed so that programs which use  *	libraries that use the ISC logging system are not required to  *	also use it.  *  *\li	The format argument is a printf(3) string, with additional arguments  *	as necessary.  *  * Requires:  *\li	lctx is a valid logging context.  *  *\li	The category and module arguments must have ids that are in the  *	range of known ids, as established by isc_log_registercategories()  *	and isc_log_registermodules().  *  *\li	level != #ISC_LOG_DYNAMIC.  ISC_LOG_DYNAMIC is used only to define  *	channels, and explicit debugging level must be identified for  *	isc_log_write() via ISC_LOG_DEBUG(level).  *  *\li	format != NULL.  *  * Ensures:  *\li	The log message is written to every channel associated with the  *	indicated category/module pair.  *  * Returns:  *\li	Nothing.  Failure to log a message is not construed as a  *	meaningful error.  */
end_comment

begin_function_decl
name|void
name|isc_log_vwrite
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%  * Write a message to the log channels, pruning duplicates that occur within  * a configurable amount of seconds (see isc_log_[sg]etduplicateinterval).  * This function is otherwise identical to isc_log_write().  */
end_comment

begin_function_decl
name|void
name|isc_log_write1
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|6
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%  * Write a message to the log channels, pruning duplicates that occur within  * a configurable amount of seconds (see isc_log_[sg]etduplicateinterval).  * This function is otherwise identical to isc_log_vwrite().  */
end_comment

begin_function_decl
name|void
name|isc_log_vwrite1
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|5
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*%  * These are four internationalized versions of the isc_log_[v]write[1]  * functions.  *  * The only difference is that they take arguments for a message  * catalog, message set, and message number, all immediately preceding the  * format argument.  The format argument becomes the default text, a la  * isc_msgcat_get.  If the message catalog is NULL, no lookup is attempted  * for a message -- which makes the message set and message number irrelevant,  * and the non-internationalized call should have probably been used instead.  *  * Yes, that means there are now *eight* interfaces to logging a message.  * Sheesh.   Make the madness stop!  */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_function_decl
name|void
name|isc_log_iwrite
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|msgset
parameter_list|,
name|int
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|8
operator|,
function_decl|9
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|isc_log_ivwrite
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|msgset
parameter_list|,
name|int
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|8
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|isc_log_iwrite1
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|msgset
parameter_list|,
name|int
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|8
operator|,
function_decl|9
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|isc_log_ivwrite1
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|isc_logcategory_t
modifier|*
name|category
parameter_list|,
name|isc_logmodule_t
modifier|*
name|module
parameter_list|,
name|int
name|level
parameter_list|,
name|isc_msgcat_t
modifier|*
name|msgcat
parameter_list|,
name|int
name|msgset
parameter_list|,
name|int
name|message
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|ISC_FORMAT_PRINTF
parameter_list|(
function_decl|8
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*@}*/
end_comment

begin_function_decl
name|void
name|isc_log_setdebuglevel
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|unsigned
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the debugging level used for logging.  *  * Notes:  *\li	Setting the debugging level to 0 disables debugging log messages.  *  * Requires:  *\li	lctx is a valid logging context.  *  * Ensures:  *\li	The debugging level is set to the requested value.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_log_getdebuglevel
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the current debugging level.  *  * Notes:  *\li	This is provided so that a program can have a notion of  *	"increment debugging level" or "decrement debugging level"  *	without needing to keep track of what the current level is.  *  *\li	A return value of 0 indicates that debugging messages are disabled.  *  * Requires:  *\li	lctx is a valid logging context.  *  * Ensures:  *\li	The current logging debugging level is returned.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_log_wouldlog
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Determine whether logging something to 'lctx' at 'level' would  * actually cause something to be logged somewhere.  *  * If #ISC_FALSE is returned, it is guaranteed that nothing would  * be logged, allowing the caller to omit unnecessary  * isc_log_write() calls and possible message preformatting.  */
end_comment

begin_function_decl
name|void
name|isc_log_setduplicateinterval
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|,
name|unsigned
name|int
name|interval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the interval over which duplicate log messages will be ignored  * by isc_log_[v]write1(), in seconds.  *  * Notes:  *\li	Increasing the duplicate interval from X to Y will not necessarily  *	filter out duplicates of messages logged in Y - X seconds since the  *	increase.  (Example: Message1 is logged at midnight.  Message2  *	is logged at 00:01:00, when the interval is only 30 seconds, causing  *	Message1 to be expired from the log message history.  Then the interval  *	is increased to 3000 (five minutes) and at 00:04:00 Message1 is logged  *	again.  It will appear the second time even though less than five  *	passed since the first occurrence.  *  * Requires:  *\li	lctx is a valid logging context.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_log_getduplicateinterval
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the current duplicate filtering interval.  *  * Requires:  *\li	lctx is a valid logging context.  *  * Returns:  *\li	The current duplicate filtering interval.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_log_settag
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|,
specifier|const
name|char
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the program name or other identifier for #ISC_LOG_PRINTTAG.  *  * Requires:  *\li	lcfg is a valid logging configuration.  *  * Notes:  *\li	If this function has not set the tag to a non-NULL, non-empty value,  *	then the #ISC_LOG_PRINTTAG channel flag will not print anything.  *	Unlike some implementations of syslog on Unix systems, you *must* set  *	the tag in order to get it logged.  It is not implicitly derived from  *	the program name (which is pretty impossible to infer portably).  *  *\li	Setting the tag to NULL or the empty string will also cause the  *	#ISC_LOG_PRINTTAG channel flag to not print anything.  If tag equals the  *	empty string, calls to isc_log_gettag will return NULL.  *  * Returns:  *\li	#ISC_R_SUCCESS	Success  *\li	#ISC_R_NOMEMORY  Resource Limit: Out of memory  *  * XXXDCL when creating a new isc_logconfig_t, it might be nice if the tag  * of the currently active isc_logconfig_t was inherited.  this does not  * currently happen.  */
end_comment

begin_function_decl
name|char
modifier|*
name|isc_log_gettag
parameter_list|(
name|isc_logconfig_t
modifier|*
name|lcfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the current identifier printed with #ISC_LOG_PRINTTAG.  *  * Requires:  *\li	lcfg is a valid logging configuration.  *  * Notes:  *\li	Since isc_log_settag() will not associate a zero-length string  *	with the logging configuration, attempts to do so will cause  *	this function to return NULL.  However, a determined programmer  *	will observe that (currently) a tag of length greater than zero  *	could be set, and then modified to be zero length.  *  * Returns:  *\li	A pointer to the current identifier, or NULL if none has been set.  */
end_comment

begin_function_decl
name|void
name|isc_log_opensyslog
parameter_list|(
specifier|const
name|char
modifier|*
name|tag
parameter_list|,
name|int
name|options
parameter_list|,
name|int
name|facility
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Initialize syslog logging.  *  * Notes:  *\li	XXXDCL NT  *	This is currently equivalent to openlog(), but is not going to remain  *	that way.  In the meantime, the arguments are all identical to  *	those used by openlog(3), as follows:  *  * \code  *		tag: The string to use in the position of the program  *			name in syslog messages.  Most (all?) syslogs  *			will use basename(argv[0]) if tag is NULL.  *  *		options: LOG_CONS, LOG_PID, LOG_NDELAY ... whatever your  *			syslog supports.  *  *		facility: The default syslog facility.  This is irrelevant  *			since isc_log_write will ALWAYS use the channel's  *			declared facility.  * \endcode  *  *\li	Zero effort has been made (yet) to accommodate systems with openlog()  *	that only takes two arguments, or to identify valid syslog  *	facilities or options for any given architecture.  *  *\li	It is necessary to call isc_log_opensyslog() to initialize  *	syslogging on machines which do not support network connections to  *	syslogd because they require a Unix domain socket to be used.  Since  *	this is a chore to determine at run-time, it is suggested that it  *	always be called by programs using the ISC logging system.  *  * Requires:  *\li	Nothing.  *  * Ensures:  *\li	openlog() is called to initialize the syslog system.  */
end_comment

begin_function_decl
name|void
name|isc_log_closefilelogs
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Close all open files used by #ISC_LOG_TOFILE channels.  *  * Notes:  *\li	This function is provided for programs that want to use their own  *	log rolling mechanism rather than the one provided internally.  *	For example, a program that wanted to keep daily logs would define  *	a channel which used #ISC_LOG_ROLLNEVER, then once a day would  *	rename the log file and call isc_log_closefilelogs().  *  *\li	#ISC_LOG_TOFILEDESC channels are unaffected.  *  * Requires:  *\li	lctx is a valid context.  *  * Ensures:  *\li	The open files are closed and will be reopened when they are  *	next needed.  */
end_comment

begin_function_decl
name|isc_logcategory_t
modifier|*
name|isc_log_categorybyname
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find a category by its name.  *  * Notes:  *\li	The string name of a category is not required to be unique.  *  * Requires:  *\li	lctx is a valid context.  *\li	name is not NULL.  *  * Returns:  *\li	A pointer to the _first_ isc_logcategory_t structure used by "name".  *  *\li	NULL if no category exists by that name.  */
end_comment

begin_function_decl
name|isc_logmodule_t
modifier|*
name|isc_log_modulebyname
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Find a module by its name.  *  * Notes:  *\li	The string name of a module is not required to be unique.  *  * Requires:  *\li	lctx is a valid context.  *\li	name is not NULL.  *  * Returns:  *\li	A pointer to the _first_ isc_logmodule_t structure used by "name".  *  *\li	NULL if no module exists by that name.  */
end_comment

begin_function_decl
name|void
name|isc_log_setcontext
parameter_list|(
name|isc_log_t
modifier|*
name|lctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Sets the context used by the libisc for logging.  *  * Requires:  *\li	lctx be a valid context.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_LOG_H */
end_comment

end_unit

