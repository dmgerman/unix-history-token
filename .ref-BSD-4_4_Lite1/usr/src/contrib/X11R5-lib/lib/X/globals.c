begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: globals.c,v 1.13 91/07/12 15:54:41 gildea Exp $  *  * Copyright 1989 Massachusetts Institute of Technology  *  */
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_comment
comment|/*  *  *                                 Global data  *  * This file should contain only those objects which must be predefined.  */
end_comment

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_include
include|#
directive|include
file|<X11/Xlibint.h>
end_include

begin_comment
comment|/*  * If possible, it is useful to have the global data default to a null value.  * Some shared library implementations are *much* happier if there isn't any  * global initialized data.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NULL_NOT_ZERO
end_ifdef

begin_comment
comment|/* then need to initialize */
end_comment

begin_define
define|#
directive|define
name|SetZero
parameter_list|(
name|t
parameter_list|,
name|var
parameter_list|,
name|z
parameter_list|)
value|t var = z
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SetZero
parameter_list|(
name|t
parameter_list|,
name|var
parameter_list|,
name|z
parameter_list|)
value|t var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USL_SHAREDLIB
end_ifdef

begin_comment
comment|/* then need extra variables */
end_comment

begin_comment
comment|/*  * If we need to define extra variables for each global  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_comment
comment|/* then ANSI C concatenation */
end_comment

begin_define
define|#
directive|define
name|ZEROINIT
parameter_list|(
name|t
parameter_list|,
name|var
parameter_list|,
name|val
parameter_list|)
value|SetZero(t,var,val); \   SetZero (long, _libX_##var##Flag, 0); \   SetZero (void *, _libX_##var##Ptr, NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else pcc concatenation */
end_comment

begin_define
define|#
directive|define
name|ZEROINIT
parameter_list|(
name|t
parameter_list|,
name|var
parameter_list|,
name|val
parameter_list|)
value|SetZero(t,var,val); \   SetZero (long, _libX_
comment|/**/
value|var
comment|/**/
value|Flag, 0); \   SetZero (void *, _libX_
comment|/**/
value|var
comment|/**/
value|Ptr, NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* concat ANSI C vs. pcc */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else not USL_SHAREDLIB */
end_comment

begin_comment
comment|/*  * no extra crud  */
end_comment

begin_define
define|#
directive|define
name|ZEROINIT
parameter_list|(
name|t
parameter_list|,
name|var
parameter_list|,
name|val
parameter_list|)
value|SetZero (t, var, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USL_SHAREDLIB */
end_comment

begin_comment
comment|/*  * Error handlers; used to be in XlibInt.c  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|funcptr
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_expr_stmt
name|ZEROINIT
argument_list|(
name|funcptr
argument_list|,
name|_XErrorFunction
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ZEROINIT
argument_list|(
name|funcptr
argument_list|,
name|_XIOErrorFunction
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ZEROINIT
argument_list|(
name|_XQEvent
operator|*
argument_list|,
name|_qfree
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Debugging information and display list; used to be in XOpenDis.c  */
end_comment

begin_expr_stmt
name|ZEROINIT
argument_list|(
name|int
argument_list|,
name|_Xdebug
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ZEROINIT
argument_list|(
name|Display
operator|*
argument_list|,
name|_XHeadOfDisplayList
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMSCONN
end_ifdef

begin_comment
comment|/* The following are how the Xstream connections are used:              */
end_comment

begin_comment
comment|/*      1)      Local connections over pseudo-tty ports.                */
end_comment

begin_comment
comment|/*      2)      SVR4 local connections using named streams or SVR3.2    */
end_comment

begin_comment
comment|/*              local connections using streams.                        */
end_comment

begin_comment
comment|/*      3)      SVR4 stream pipe code. This code is proprietary and     */
end_comment

begin_comment
comment|/*              the actual code is not included in the MIT distribution.*/
end_comment

begin_comment
comment|/*      4)      remote connections using tcp                            */
end_comment

begin_comment
comment|/*      5)      remote connections using StarLan                        */
end_comment

begin_comment
comment|/*  * descriptor block for streams connections  */
end_comment

begin_include
include|#
directive|include
file|"Xstreams.h"
end_include

begin_decl_stmt
name|char
name|_XsTypeOfStream
index|[
literal|100
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|write
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|close
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_function_decl
specifier|extern
name|int
name|_XsSetupSpStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsSetupNamedStream
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|_XsSetupLocalStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsConnectLocalClient
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsCallLocalServer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsReadLocalStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsErrorCall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsWriteLocalStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsCloseLocalStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsSetupTliStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsConnectTliClient
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsCallTliServer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsReadTliStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsWriteTliStream
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XsCloseTliStream
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|Xstream
name|_XsStream
index|[]
init|=
block|{
block|{
comment|/* local connections using pseudo-ttys */
name|_XsSetupLocalStream
block|,
name|_XsConnectLocalClient
block|,
name|_XsCallLocalServer
block|,
name|_XsReadLocalStream
block|,
name|_XsErrorCall
block|,
name|write
block|,
name|close
block|,
name|NULL
block|}
block|,
block|{
ifdef|#
directive|ifdef
name|SVR4
comment|/* local connections using named streams */
name|_XsSetupNamedStream
block|,
else|#
directive|else
comment|/* local connections using streams */
name|_XsSetupLocalStream
block|,
endif|#
directive|endif
name|_XsConnectLocalClient
block|,
name|_XsCallLocalServer
block|,
name|_XsReadLocalStream
block|,
name|_XsErrorCall
block|,
name|write
block|,
name|close
block|,
name|NULL
block|}
block|,
comment|/* Enhanced Application Compatibility Support */
block|{
ifdef|#
directive|ifdef
name|SVR4
comment|/* SVR4 stream pipe code */
name|_XsSetupSpStream
block|,
else|#
directive|else
name|_XsSetupLocalStream
block|,
endif|#
directive|endif
name|_XsConnectLocalClient
block|,
name|_XsCallLocalServer
block|,
name|_XsReadLocalStream
block|,
name|_XsErrorCall
block|,
name|write
block|,
name|close
block|,
name|NULL
block|}
block|,
comment|/* End Enhanced Application Compatibility Support */
block|{
comment|/* remote connections using tcp */
name|_XsSetupTliStream
block|,
name|_XsConnectTliClient
block|,
name|_XsCallTliServer
block|,
name|_XsReadLocalStream
block|,
name|_XsErrorCall
block|,
name|write
block|,
name|close
block|,
name|NULL
block|}
block|,
block|{
comment|/* remote connections using StarLan */
name|_XsSetupTliStream
block|,
name|_XsConnectTliClient
block|,
name|_XsCallTliServer
block|,
name|_XsReadLocalStream
block|,
name|_XsErrorCall
block|,
name|write
block|,
name|close
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STREAMSCONN */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XTEST1
end_ifdef

begin_comment
comment|/*  * Stuff for input synthesis extension:  */
end_comment

begin_comment
comment|/*  * Holds the two event type codes for this extension.  The event type codes  * for this extension may vary depending on how many extensions are installed  * already, so the initial values given below will be added to the base event  * code that is aquired when this extension is installed.  *  * These two variables must be available to programs that use this extension.  */
end_comment

begin_decl_stmt
name|int
name|XTestInputActionType
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|XTestFakeAckType
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * NOTE: any additional external definition NEED  * to be inserted BELOW this point!!!  */
end_comment

begin_comment
comment|/*  * NOTE: any additional external definition NEED  * to be inserted ABOVE this point!!!  */
end_comment

begin_decl_stmt
name|_XQEvent
modifier|*
name|_qfree
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|_qfreeFlag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|_qfreePtr
init|=
name|NULL
decl_stmt|;
end_decl_stmt

end_unit

