begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ModExp / RSA (with/without KM) plugin API  *  * The application will load a dynamic library which  * exports entrypoint(s) defined in this file.  *  * This set of entrypoints provides only a multithreaded,  * synchronous-within-each-thread, facility.  *  *  * This file is Copyright 1998-2000 nCipher Corporation Limited.  *  * Redistribution and use in source and binary forms, with opr without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the copyright notice,  *    this list of conditions, and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions, and the following  *    disclaimer, in the documentation and/or other materials provided  *    with the distribution  *  * IN NO EVENT SHALL NCIPHER CORPORATION LIMITED (`NCIPHER') AND/OR  * ANY OTHER AUTHORS OR DISTRIBUTORS OF THIS FILE BE LIABLE for any  * damages arising directly or indirectly from this file, its use or  * this licence.  Without prejudice to the generality of the  * foregoing: all liability shall be excluded for direct, indirect,  * special, incidental, consequential or other damages or any loss of  * profits, business, revenue goodwill or anticipated savings;  * liability shall be excluded even if nCipher or anyone else has been  * advised of the possibility of damage.  In any event, if the  * exclusion of liability is not effective, the liability of nCipher  * or any author or distributor shall be limited to the lesser of the  * price paid and 1,000 pounds sterling. This licence only fails to  * exclude or limit liability for death or personal injury arising out  * of negligence, and only to the extent that such an exclusion or  * limitation is not effective.  *  * NCIPHER AND THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ALL  * AND ANY WARRANTIES (WHETHER EXPRESS OR IMPLIED), including, but not  * limited to, any implied warranties of merchantability, fitness for  * a particular purpose, satisfactory quality, and/or non-infringement  * of any third party rights.  *  * US Government use: This software and documentation is Commercial  * Computer Software and Computer Software Documentation, as defined in  * sub-paragraphs (a)(1) and (a)(5) of DFAR 252.227-7014, "Rights in  * Noncommercial Computer Software and Noncommercial Computer Software  * Documentation."  Use, duplication or disclosure by the Government is  * subject to the terms and conditions specified here.  *  * By using or distributing this file you will be accepting these  * terms and conditions, including the limitation of liability and  * lack of warranty.  If you do not wish to accept these terms and  * conditions, DO NOT USE THE FILE.  *  *  * The actual dynamically loadable plugin, and the library files for  * static linking, which are also provided in some distributions, are  * not covered by the licence described above.  You should have  * received a separate licence with terms and conditions for these  * library files; if you received the library files without a licence,  * please contact nCipher.  *  *  * $Id: hwcryptohook.h,v 1.3 2001/07/04 12:26:39 ben Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HWCRYPTOHOOK_H
end_ifndef

begin_define
define|#
directive|define
name|HWCRYPTOHOOK_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HWCRYPTOHOOK_DECLARE_APPTYPES
end_ifndef

begin_define
define|#
directive|define
name|HWCRYPTOHOOK_DECLARE_APPTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HWCRYPTOHOOK_ERROR_FAILED
value|-1
end_define

begin_define
define|#
directive|define
name|HWCRYPTOHOOK_ERROR_FALLBACK
value|-2
end_define

begin_define
define|#
directive|define
name|HWCRYPTOHOOK_ERROR_MPISIZE
value|-3
end_define

begin_if
if|#
directive|if
name|HWCRYPTOHOOK_DECLARE_APPTYPES
end_if

begin_comment
comment|/* These structs are defined by the application and opaque to the  * crypto plugin.  The application may define these as it sees fit.  * Default declarations are provided here, but the application may  *  #define HWCRYPTOHOOK_DECLARE_APPTYPES 0  * to prevent these declarations, and instead provide its own  * declarations of these types.  (Pointers to them must still be  * ordinary pointers to structs or unions, or the resulting combined  * program will have a type inconsistency.)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_MutexValue
name|HWCryptoHook_Mutex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_CondVarValue
name|HWCryptoHook_CondVar
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_PassphraseContextValue
name|HWCryptoHook_PassphraseContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_CallerContextValue
name|HWCryptoHook_CallerContext
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HWCRYPTOHOOK_DECLARE_APPTYPES */
end_comment

begin_comment
comment|/* These next two structs are opaque to the application.  The crypto  * plugin will return pointers to them; the caller simply manipulates  * the pointers.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_Context
modifier|*
name|HWCryptoHook_ContextHandle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|HWCryptoHook_RSAKey
modifier|*
name|HWCryptoHook_RSAKeyHandle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|HWCryptoHook_ErrMsgBuf
typedef|;
end_typedef

begin_comment
comment|/* Used for error reporting.  When a HWCryptoHook function fails it  * will return a sentinel value (0 for pointer-valued functions, or a  * negative number, usually HWCRYPTOHOOK_ERROR_FAILED, for  * integer-valued ones).  It will, if an ErrMsgBuf is passed, also put  * an error message there.  *   * size is the size of the buffer, and will not be modified.  If you  * pass 0 for size you must pass 0 for buf, and nothing will be  * recorded (just as if you passed 0 for the struct pointer).  * Messages written to the buffer will always be null-terminated, even  * when truncated to fit within size bytes.  *  * The contents of the buffer are not defined if there is no error.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HWCryptoHook_MPIStruct
block|{
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
name|HWCryptoHook_MPI
typedef|;
end_typedef

begin_comment
comment|/* When one of these is returned, a pointer is passed to the function.  * At call, size is the space available.  Afterwards it is updated to  * be set to the actual length (which may be more than the space available,  * if there was not enough room and the result was truncated).  * buf (the pointer) is not updated.  *  * size is in bytes and may be zero at call or return, but must be a  * multiple of the limb size.  Zero limbs at the MS end are not  * permitted.  */
end_comment

begin_define
define|#
directive|define
name|HWCryptoHook_InitFlags_FallbackModExp
value|0x0002UL
end_define

begin_define
define|#
directive|define
name|HWCryptoHook_InitFlags_FallbackRSAImmed
value|0x0004UL
end_define

begin_comment
comment|/* Enable requesting fallback to software in case of problems with the  * hardware support.  This indicates to the crypto provider that the  * application is prepared to fall back to software operation if the  * ModExp* or RSAImmed* functions return HWCRYPTOHOOK_ERROR_FALLBACK.  * Without this flag those calls will never return  * HWCRYPTOHOOK_ERROR_FALLBACK.  The flag will also cause the crypto  * provider to avoid repeatedly attempting to contact dead hardware  * within a short interval, if appropriate.  */
end_comment

begin_define
define|#
directive|define
name|HWCryptoHook_InitFlags_SimpleForkCheck
value|0x0010UL
end_define

begin_comment
comment|/* Without _SimpleForkCheck the library is allowed to assume that the  * application will not fork and call the library in the child(ren).  *  * When it is specified, this is allowed.  However, after a fork  * neither parent nor child may unload any loaded keys or call  * _Finish.  Instead, they should call exit (or die with a signal)  * without calling _Finish.  After all the children have died the  * parent may unload keys or call _Finish.  *  * This flag only has any effect on UN*X platforms.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|flags
decl_stmt|;
name|void
modifier|*
name|logstream
decl_stmt|;
comment|/* usually a FILE*.  See below. */
name|size_t
name|limbsize
decl_stmt|;
comment|/* bignum format - size of radix type, must be power of 2 */
name|int
name|mslimbfirst
decl_stmt|;
comment|/* 0 or 1 */
name|int
name|msbytefirst
decl_stmt|;
comment|/* 0 or 1; -1 = native */
comment|/* All the callback functions should return 0 on success, or a    * nonzero integer (whose value will be visible in the error message    * put in the buffer passed to the call).    *    * If a callback is not available pass a null function pointer.    *    * The callbacks may not call down again into the crypto plugin.    */
comment|/* For thread-safety.  Set everything to 0 if you promise only to be    * singlethreaded.  maxsimultaneous is the number of calls to    * ModExp[Crt]/RSAImmed{Priv,Pub}/RSA.  If you don't know what to    * put there then say 0 and the hook library will use a default.    *    * maxmutexes is a small limit on the number of simultaneous mutexes    * which will be requested by the library.  If there is no small    * limit, set it to 0.  If the crypto plugin cannot create the    * advertised number of mutexes the calls to its functions may fail.    * If a low number of mutexes is advertised the plugin will try to    * do the best it can.  Making larger numbers of mutexes available    * may improve performance and parallelism by reducing contention    * over critical sections.  Unavailability of any mutexes, implying    * single-threaded operation, should be indicated by the setting    * mutex_init et al to 0.    */
name|int
name|maxmutexes
decl_stmt|;
name|int
name|maxsimultaneous
decl_stmt|;
name|size_t
name|mutexsize
decl_stmt|;
name|int
function_decl|(
modifier|*
name|mutex_init
function_decl|)
parameter_list|(
name|HWCryptoHook_Mutex
modifier|*
parameter_list|,
name|HWCryptoHook_CallerContext
modifier|*
name|cactx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mutex_acquire
function_decl|)
parameter_list|(
name|HWCryptoHook_Mutex
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mutex_release
function_decl|)
parameter_list|(
name|HWCryptoHook_Mutex
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mutex_destroy
function_decl|)
parameter_list|(
name|HWCryptoHook_Mutex
modifier|*
parameter_list|)
function_decl|;
comment|/* For greater efficiency, can use condition vars internally for    * synchronisation.  In this case maxsimultaneous is ignored, but    * the other mutex stuff must be available.  In singlethreaded    * programs, set everything to 0.    */
name|size_t
name|condvarsize
decl_stmt|;
name|int
function_decl|(
modifier|*
name|condvar_init
function_decl|)
parameter_list|(
name|HWCryptoHook_CondVar
modifier|*
parameter_list|,
name|HWCryptoHook_CallerContext
modifier|*
name|cactx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|condvar_wait
function_decl|)
parameter_list|(
name|HWCryptoHook_CondVar
modifier|*
parameter_list|,
name|HWCryptoHook_Mutex
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|condvar_signal
function_decl|)
parameter_list|(
name|HWCryptoHook_CondVar
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|condvar_broadcast
function_decl|)
parameter_list|(
name|HWCryptoHook_CondVar
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|condvar_destroy
function_decl|)
parameter_list|(
name|HWCryptoHook_CondVar
modifier|*
parameter_list|)
function_decl|;
comment|/* The semantics of acquiring and releasing mutexes and broadcasting    * and waiting on condition variables are expected to be those from    * POSIX threads (pthreads).  The mutexes may be (in pthread-speak)    * fast mutexes, recursive mutexes, or nonrecursive ones.    *     * The _release/_signal/_broadcast and _destroy functions must    * always succeed when given a valid argument; if they are given an    * invalid argument then the program (crypto plugin + application)    * has an internal error, and they should abort the program.    */
name|int
function_decl|(
modifier|*
name|getpassphrase
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt_info
parameter_list|,
name|int
modifier|*
name|len_io
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|HWCryptoHook_PassphraseContext
modifier|*
name|ppctx
parameter_list|,
name|HWCryptoHook_CallerContext
modifier|*
name|cactx
parameter_list|)
function_decl|;
comment|/* Passphrases and the prompt_info, if they contain high-bit-set    * characters, are UTF-8.  The prompt_info may be a null pointer if    * no prompt information is available (it should not be an empty    * string).  It will not contain text like `enter passphrase';    * instead it might say something like `Operator Card for John    * Smith' or `SmartCard in nFast Module #1, Slot #1'.    *    * buf points to a buffer in which to return the passphrase; on    * entry *len_io is the length of the buffer.  It should be updated    * by the callback.  The returned passphrase should not be    * null-terminated by the callback.    */
name|int
function_decl|(
modifier|*
name|getphystoken
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|prompt_info
parameter_list|,
specifier|const
name|char
modifier|*
name|wrong_info
parameter_list|,
name|HWCryptoHook_PassphraseContext
modifier|*
name|ppctx
parameter_list|,
name|HWCryptoHook_CallerContext
modifier|*
name|cactx
parameter_list|)
function_decl|;
comment|/* Requests that the human user physically insert a different    * smartcard, DataKey, etc.  The plugin should check whether the    * currently inserted token(s) are appropriate, and if they are it    * should not make this call.    *    * prompt_info is as before.  wrong_info is a description of the    * currently inserted token(s) so that the user is told what    * something is.  wrong_info, like prompt_info, may be null, but    * should not be an empty string.  Its contents should be    * syntactically similar to that of prompt_info.     */
comment|/* Note that a single LoadKey operation might cause several calls to    * getpassphrase and/or requestphystoken.  If requestphystoken is    * not provided (ie, a null pointer is passed) then the plugin may    * not support loading keys for which authorisation by several cards    * is required.  If getpassphrase is not provided then cards with    * passphrases may not be supported.    *    * getpassphrase and getphystoken do not need to check that the    * passphrase has been entered correctly or the correct token    * inserted; the crypto plugin will do that.  If this is not the    * case then the crypto plugin is responsible for calling these    * routines again as appropriate until the correct token(s) and    * passphrase(s) are supplied as required, or until any retry limits    * implemented by the crypto plugin are reached.    *    * In either case, the application must allow the user to say `no'    * or `cancel' to indicate that they do not know the passphrase or    * have the appropriate token; this should cause the callback to    * return nonzero indicating error.    */
name|void
function_decl|(
modifier|*
name|logmessage
function_decl|)
parameter_list|(
name|void
modifier|*
name|logstream
parameter_list|,
specifier|const
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
comment|/* A log message will be generated at least every time something goes    * wrong and an ErrMsgBuf is filled in (or would be if one was    * provided).  Other diagnostic information may be written there too,    * including more detailed reasons for errors which are reported in an    * ErrMsgBuf.    *    * When a log message is generated, this callback is called.  It    * should write a message to the relevant logging arrangements.    *    * The message string passed will be null-terminated and may be of arbitrary    * length.  It will not be prefixed by the time and date, nor by the    * name of the library that is generating it - if this is required,    * the logmessage callback must do it.  The message will not have a    * trailing newline (though it may contain internal newlines).    *    * If a null pointer is passed for logmessage a default function is    * used.  The default function treats logstream as a FILE* which has    * been converted to a void*.  If logstream is 0 it does nothing.    * Otherwise it prepends the date and time and library name and    * writes the message to logstream.  Each line will be prefixed by a    * descriptive string containing the date, time and identity of the    * crypto plugin.  Errors on the logstream are not reported    * anywhere, and the default function doesn't flush the stream, so    * the application must set the buffering how it wants it.    *    * The crypto plugin may also provide a facility to have copies of    * log messages sent elsewhere, and or for adjusting the verbosity    * of the log messages; any such facilities will be configured by    * external means.    */
block|}
name|HWCryptoHook_InitInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HWCryptoHook_ContextHandle
name|HWCryptoHook_Init_t
parameter_list|(
specifier|const
name|HWCryptoHook_InitInfo
modifier|*
name|initinfo
parameter_list|,
name|size_t
name|initinfosize
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|,
name|HWCryptoHook_CallerContext
modifier|*
name|cactx
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_Init_t
name|HWCryptoHook_Init
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Caller should set initinfosize to the size of the HWCryptoHook struct,  * so it can be extended later.  *  * On success, a message for display or logging by the server,  * including the name and version number of the plugin, will be filled  * in into *errors; on failure *errors is used for error handling, as  * usual.  */
end_comment

begin_comment
comment|/* All these functions return 0 on success, HWCRYPTOHOOK_ERROR_FAILED  * on most failures.  HWCRYPTOHOOK_ERROR_MPISIZE means at least one of  * the output MPI buffer(s) was too small; the sizes of all have been  * set to the desired size (and for those where the buffer was large  * enough, the value may have been copied in), and no error message  * has been recorded.  *  * You may pass 0 for the errors struct.  In any case, unless you set  * _NoStderr at init time then messages may be reported to stderr.  */
end_comment

begin_comment
comment|/* The RSAImmed* functions (and key managed RSA) only work with  * modules which have an RSA patent licence - currently that means KM  * units; the ModExp* ones work with all modules, so you need a patent  * licence in the software in the US.  They are otherwise identical.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|HWCryptoHook_Finish_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_Finish_t
name|HWCryptoHook_Finish
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* You must not have any calls going or keys loaded when you call this. */
end_comment

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RandomBytes_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RandomBytes_t
name|HWCryptoHook_RandomBytes
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_ModExp_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
name|HWCryptoHook_MPI
name|a
parameter_list|,
name|HWCryptoHook_MPI
name|p
parameter_list|,
name|HWCryptoHook_MPI
name|n
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_ModExp_t
name|HWCryptoHook_ModExp
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSAImmedPub_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
name|HWCryptoHook_MPI
name|m
parameter_list|,
name|HWCryptoHook_MPI
name|e
parameter_list|,
name|HWCryptoHook_MPI
name|n
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSAImmedPub_t
name|HWCryptoHook_RSAImmedPub
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_ModExpCRT_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
name|HWCryptoHook_MPI
name|a
parameter_list|,
name|HWCryptoHook_MPI
name|p
parameter_list|,
name|HWCryptoHook_MPI
name|q
parameter_list|,
name|HWCryptoHook_MPI
name|dmp1
parameter_list|,
name|HWCryptoHook_MPI
name|dmq1
parameter_list|,
name|HWCryptoHook_MPI
name|iqmp
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_ModExpCRT_t
name|HWCryptoHook_ModExpCRT
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSAImmedPriv_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
name|HWCryptoHook_MPI
name|m
parameter_list|,
name|HWCryptoHook_MPI
name|p
parameter_list|,
name|HWCryptoHook_MPI
name|q
parameter_list|,
name|HWCryptoHook_MPI
name|dmp1
parameter_list|,
name|HWCryptoHook_MPI
name|dmq1
parameter_list|,
name|HWCryptoHook_MPI
name|iqmp
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSAImmedPriv_t
name|HWCryptoHook_RSAImmedPriv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The RSAImmed* and ModExp* functions may return E_FAILED or  * E_FALLBACK for failure.  *  * E_FAILED means the failure is permanent and definite and there  *    should be no attempt to fall back to software.  (Eg, for some  *    applications, which support only the acceleration-only  *    functions, the `key material' may actually be an encoded key  *    identifier, and doing the operation in software would give wrong  *    answers.)  *  * E_FALLBACK means that doing the computation in software would seem  *    reasonable.  If an application pays attention to this and is  *    able to fall back, it should also set the Fallback init flags.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSALoadKey_t
parameter_list|(
name|HWCryptoHook_ContextHandle
name|hwctx
parameter_list|,
specifier|const
name|char
modifier|*
name|key_ident
parameter_list|,
name|HWCryptoHook_RSAKeyHandle
modifier|*
name|keyhandle_r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|,
name|HWCryptoHook_PassphraseContext
modifier|*
name|ppctx
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSALoadKey_t
name|HWCryptoHook_RSALoadKey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The key_ident is a null-terminated string configured by the  * user via the application's usual configuration mechanisms.  * It is provided to the user by the crypto provider's key management  * system.  The user must be able to enter at least any string of between  * 1 and 1023 characters inclusive, consisting of printable 7-bit  * ASCII characters.  The provider should avoid using  * any characters except alphanumerics and the punctuation  * characters  _ - + . / @ ~  (the user is expected to be able  * to enter these without quoting).  The string may be case-sensitive.  * The application may allow the user to enter other NULL-terminated strings,  * and the provider must cope (returning an error if the string is not  * valid).  *  * If the key does not exist, no error is recorded and 0 is returned;  * keyhandle_r will be set to 0 instead of to a key handle.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSAGetPublicKey_t
parameter_list|(
name|HWCryptoHook_RSAKeyHandle
name|k
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|n
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|e
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSAGetPublicKey_t
name|HWCryptoHook_RSAGetPublicKey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The crypto plugin will not store certificates.  *  * Although this function for acquiring the public key value is  * provided, it is not the purpose of this API to deal fully with the  * handling of the public key.  *  * It is expected that the crypto supplier's key generation program  * will provide general facilities for producing X.509  * self-certificates and certificate requests in PEM format.  These  * will be given to the user so that they can configure them in the  * application, send them to CAs, or whatever.  *  * In case this kind of certificate handling is not appropriate, the  * crypto supplier's key generation program should be able to be  * configured not to generate such a self-certificate or certificate  * request.  Then the application will need to do all of this, and  * will need to store and handle the public key and certificates  * itself.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSAUnloadKey_t
parameter_list|(
name|HWCryptoHook_RSAKeyHandle
name|k
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSAUnloadKey_t
name|HWCryptoHook_RSAUnloadKey
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Might fail due to locking problems, or other serious internal problems. */
end_comment

begin_typedef
typedef|typedef
name|int
name|HWCryptoHook_RSA_t
parameter_list|(
name|HWCryptoHook_MPI
name|m
parameter_list|,
name|HWCryptoHook_RSAKeyHandle
name|k
parameter_list|,
name|HWCryptoHook_MPI
modifier|*
name|r
parameter_list|,
specifier|const
name|HWCryptoHook_ErrMsgBuf
modifier|*
name|errors
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|extern
name|HWCryptoHook_RSA_t
name|HWCryptoHook_RSA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RSA private key operation (sign or decrypt) - raw, unpadded. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*HWCRYPTOHOOK_H*/
end_comment

end_unit

