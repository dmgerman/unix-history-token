begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: entropy.h,v 1.23.2.1.10.1 2004/03/06 08:14:40 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_ENTROPY_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_ENTROPY_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Entropy  *  * The entropy API  *  * MP:  *	The entropy object is locked internally.  All callbacks into  *	application-provided functions (for setup, gathering, and  *	shutdown of sources) are guaranteed to be called with the  *	entropy API lock held.  This means these functions are  *	not permitted to call back into the entropy API.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	A buffer, used as an entropy pool.  *  * Security:  *	While this code is believed to implement good entropy gathering  *	and distribution, it has not been reviewed by a cryptographic  *	expert.  *  *	Since the added entropy is only as good as the sources used,  *	this module could hand out bad data and never know it.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*  * Entropy callback function.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_entropystart_t
function_decl|)
parameter_list|(
name|isc_entropysource_t
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_boolean_t
name|blocking
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_entropyget_t
function_decl|)
parameter_list|(
name|isc_entropysource_t
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_boolean_t
name|blocking
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|isc_entropystop_t
function_decl|)
parameter_list|(
name|isc_entropysource_t
modifier|*
name|source
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/***  *** Flags.  ***/
end_comment

begin_comment
comment|/*  * _GOODONLY  *	Extract only "good" data; return failure if there is not enough  *	data available and there are no sources which we can poll to get  *	data, or those sources are empty.  *  * _PARTIAL  *	Extract as much good data as possible, but if there isn't enough  *	at hand, return what is available.  This flag only makes sense  *	when used with _GOODONLY.  *  * _BLOCKING  *	Block the task until data is available.  This is contrary to the  *	ISC task system, where tasks should never block.  However, if  *	this is a special purpose application where blocking a task is  *	acceptable (say, an offline zone signer) this flag may be set.  *	This flag only makes sense when used with _GOODONLY, and will  *	block regardless of the setting for _PARTIAL.  */
end_comment

begin_define
define|#
directive|define
name|ISC_ENTROPY_GOODONLY
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|ISC_ENTROPY_PARTIAL
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|ISC_ENTROPY_BLOCKING
value|0x00000004U
end_define

begin_comment
comment|/*  * _ESTIMATE  *	Estimate the amount of entropy contained in the sample pool.  *	If this is not set, the source will be gathered and perodically  *	mixed into the entropy pool, but no increment in contained entropy  *	will be assumed.  This flag only makes sense on sample sources.  */
end_comment

begin_define
define|#
directive|define
name|ISC_ENTROPYSOURCE_ESTIMATE
value|0x00000001U
end_define

begin_comment
comment|/*  * For use with isc_entropy_usebestsource().  *  * _KEYBOARDYES  *	Use the keyboard as the only entropy source.  * _KEYBOARDNO  *	Never use the keyboard as an entropy source.  * _KEYBOARDMAYBE  *	Use the keyboard as an entropy source only if opening the  *	random device fails.  */
end_comment

begin_define
define|#
directive|define
name|ISC_ENTROPY_KEYBOARDYES
value|1
end_define

begin_define
define|#
directive|define
name|ISC_ENTROPY_KEYBOARDNO
value|2
end_define

begin_define
define|#
directive|define
name|ISC_ENTROPY_KEYBOARDMAYBE
value|3
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/***  *** Functions  ***/
name|isc_result_t
name|isc_entropy_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_entropy_t
modifier|*
modifier|*
name|entp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new entropy object.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_attach
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|isc_entropy_t
modifier|*
modifier|*
name|entp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attaches to an entropy object.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_detach
parameter_list|(
name|isc_entropy_t
modifier|*
modifier|*
name|entp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detaches from an entropy object.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_createfilesource
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new entropy source from a file.  *  * The file is assumed to contain good randomness, and will be mixed directly  * into the pool with every byte adding 8 bits of entropy.  *  * The file will be put into non-blocking mode, so it may be a device file,  * such as /dev/random.  /dev/urandom should not be used here if it can  * be avoided, since it will always provide data even if it isn't good.  * We will make as much pseudorandom data as we need internally if our  * caller asks for it.  *  * If we hit end-of-file, we will stop reading from this source.  Callers  * who require strong random data will get failure when our pool drains.  * The file will never be opened/read again once EOF is reached.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_destroysource
parameter_list|(
name|isc_entropysource_t
modifier|*
modifier|*
name|sourcep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Removes an entropy source from the entropy system.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_createsamplesource
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|isc_entropysource_t
modifier|*
modifier|*
name|sourcep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an entropy source that consists of samples.  Each sample is added  * to the source via isc_entropy_addsamples(), below.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_createcallbacksource
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|isc_entropystart_t
name|start
parameter_list|,
name|isc_entropyget_t
name|get
parameter_list|,
name|isc_entropystop_t
name|stop
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_entropysource_t
modifier|*
modifier|*
name|sourcep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an entropy source that is polled via a callback.  This would  * be used when keyboard input is used, or a GUI input method.  It can  * also be used to hook in any external entropy source.  *  * Samples are added via isc_entropy_addcallbacksample(), below.  * _addcallbacksample() is the only function which may be called from  * within an entropy API callback function.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_stopcallbacksources
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Call the stop functions for callback sources that have had their  * start functions called.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_addcallbacksample
parameter_list|(
name|isc_entropysource_t
modifier|*
name|source
parameter_list|,
name|isc_uint32_t
name|sample
parameter_list|,
name|isc_uint32_t
name|extra
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_entropy_addsample
parameter_list|(
name|isc_entropysource_t
modifier|*
name|source
parameter_list|,
name|isc_uint32_t
name|sample
parameter_list|,
name|isc_uint32_t
name|extra
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add a sample to the sample source.  The sample MUST be a timestamp  * that increases over time, with the exception of wrap-around for  * extremely high resolution timers which will quickly wrap-around  * a 32-bit integer.  *  * The "extra" parameter is used only to add a bit more unpredictable  * data.  It is not used other than included in the hash of samples.  *  * When in an entropy API callback function, _addcallbacksource() must be  * used.  At all other times, _addsample() must be used.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_getdata
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|unsigned
name|int
modifier|*
name|returned
parameter_list|,
name|unsigned
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Extract data from the entropy pool.  This may load the pool from various  * sources.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_putdata
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|isc_uint32_t
name|entropy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add "length" bytes in "data" to the entropy pool, incrementing the pool's  * entropy count by "entropy."  *  * These bytes will prime the pseudorandom portion even no entropy is actually  * added.  */
end_comment

begin_function_decl
name|void
name|isc_entropy_stats
parameter_list|(
name|isc_entropy_t
modifier|*
name|ent
parameter_list|,
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dump some (trivial) stats to the stdio stream "out".  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_entropy_usebestsource
parameter_list|(
name|isc_entropy_t
modifier|*
name|ectx
parameter_list|,
name|isc_entropysource_t
modifier|*
modifier|*
name|source
parameter_list|,
specifier|const
name|char
modifier|*
name|randomfile
parameter_list|,
name|int
name|use_keyboard
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Use whatever source of entropy is best.  *  * Notes:  *	If "randomfile" is not NULL, open it with  *	isc_entropy_createfilesource().   *  *	If "randomfile" is NULL and the system's random device was detected  *	when the program was configured and built, open that device with  *	isc_entropy_createfilesource().   *  *	If "use_keyboard" is ISC_ENTROPY_KEYBOARDYES, then always open  *	the keyboard as an entropy source (possibly in addition to  *	"randomfile" or the random device).  *  *	If "use_keyboard" is ISC_ENTROPY_KEYBOARDMAYBE, open the keyboard only  *	if opening the random file/device fails.  A message will be  *	printed describing the need for keyboard input.  *  *	If "use_keyboard" is ISC_ENTROPY_KEYBOARDNO, the keyboard will  *	never be opened.  *  * Returns:  *	ISC_R_SUCCESS if at least one source of entropy could be started.  *  *	ISC_R_NOENTROPY if use_keyboard is ISC_ENTROPY_KEYBOARDNO and  *	there is no random device pathname compiled into the program.  *  *	A return code from isc_entropy_createfilesource() or  *	isc_entropy_createcallbacksource().  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_ENTROPY_H */
end_comment

end_unit

