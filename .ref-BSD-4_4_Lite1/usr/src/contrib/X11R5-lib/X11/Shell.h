begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* * $XConsortium: Shell.h,v 1.23 91/05/04 20:59:47 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtShell_h
end_ifndef

begin_define
define|#
directive|define
name|_XtShell_h
end_define

begin_comment
comment|/***********************************************************************  *  * Shell Widget  *  ***********************************************************************/
end_comment

begin_comment
comment|/*  * Shell-specific resources names, classes, and a representation type.  */
end_comment

begin_comment
comment|/* The string definitions are automatically generated. */
end_comment

begin_comment
comment|/* Do not edit. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XTSTRINGDEFINES
end_ifdef

begin_define
define|#
directive|define
name|XtNiconName
value|"iconName"
end_define

begin_define
define|#
directive|define
name|XtCIconName
value|"IconName"
end_define

begin_define
define|#
directive|define
name|XtNiconPixmap
value|"iconPixmap"
end_define

begin_define
define|#
directive|define
name|XtCIconPixmap
value|"IconPixmap"
end_define

begin_define
define|#
directive|define
name|XtNiconWindow
value|"iconWindow"
end_define

begin_define
define|#
directive|define
name|XtCIconWindow
value|"IconWindow"
end_define

begin_define
define|#
directive|define
name|XtNiconMask
value|"iconMask"
end_define

begin_define
define|#
directive|define
name|XtCIconMask
value|"IconMask"
end_define

begin_define
define|#
directive|define
name|XtNwindowGroup
value|"windowGroup"
end_define

begin_define
define|#
directive|define
name|XtCWindowGroup
value|"WindowGroup"
end_define

begin_define
define|#
directive|define
name|XtNvisual
value|"visual"
end_define

begin_define
define|#
directive|define
name|XtCVisual
value|"Visual"
end_define

begin_define
define|#
directive|define
name|XtNtitleEncoding
value|"titleEncoding"
end_define

begin_define
define|#
directive|define
name|XtCTitleEncoding
value|"TitleEncoding"
end_define

begin_define
define|#
directive|define
name|XtNsaveUnder
value|"saveUnder"
end_define

begin_define
define|#
directive|define
name|XtCSaveUnder
value|"SaveUnder"
end_define

begin_define
define|#
directive|define
name|XtNtransient
value|"transient"
end_define

begin_define
define|#
directive|define
name|XtCTransient
value|"Transient"
end_define

begin_define
define|#
directive|define
name|XtNoverrideRedirect
value|"overrideRedirect"
end_define

begin_define
define|#
directive|define
name|XtCOverrideRedirect
value|"OverrideRedirect"
end_define

begin_define
define|#
directive|define
name|XtNtransientFor
value|"transientFor"
end_define

begin_define
define|#
directive|define
name|XtCTransientFor
value|"TransientFor"
end_define

begin_define
define|#
directive|define
name|XtNiconNameEncoding
value|"iconNameEncoding"
end_define

begin_define
define|#
directive|define
name|XtCIconNameEncoding
value|"IconNameEncoding"
end_define

begin_define
define|#
directive|define
name|XtNallowShellResize
value|"allowShellResize"
end_define

begin_define
define|#
directive|define
name|XtCAllowShellResize
value|"AllowShellResize"
end_define

begin_define
define|#
directive|define
name|XtNcreatePopupChildProc
value|"createPopupChildProc"
end_define

begin_define
define|#
directive|define
name|XtCCreatePopupChildProc
value|"CreatePopupChildProc"
end_define

begin_define
define|#
directive|define
name|XtNtitle
value|"title"
end_define

begin_define
define|#
directive|define
name|XtCTitle
value|"Title"
end_define

begin_define
define|#
directive|define
name|XtRAtom
value|"Atom"
end_define

begin_define
define|#
directive|define
name|XtNargc
value|"argc"
end_define

begin_define
define|#
directive|define
name|XtCArgc
value|"Argc"
end_define

begin_define
define|#
directive|define
name|XtNargv
value|"argv"
end_define

begin_define
define|#
directive|define
name|XtCArgv
value|"Argv"
end_define

begin_define
define|#
directive|define
name|XtNiconX
value|"iconX"
end_define

begin_define
define|#
directive|define
name|XtCIconX
value|"IconX"
end_define

begin_define
define|#
directive|define
name|XtNiconY
value|"iconY"
end_define

begin_define
define|#
directive|define
name|XtCIconY
value|"IconY"
end_define

begin_define
define|#
directive|define
name|XtNinput
value|"input"
end_define

begin_define
define|#
directive|define
name|XtCInput
value|"Input"
end_define

begin_define
define|#
directive|define
name|XtNiconic
value|"iconic"
end_define

begin_define
define|#
directive|define
name|XtCIconic
value|"Iconic"
end_define

begin_define
define|#
directive|define
name|XtNinitialState
value|"initialState"
end_define

begin_define
define|#
directive|define
name|XtCInitialState
value|"InitialState"
end_define

begin_define
define|#
directive|define
name|XtNgeometry
value|"geometry"
end_define

begin_define
define|#
directive|define
name|XtCGeometry
value|"Geometry"
end_define

begin_define
define|#
directive|define
name|XtNbaseWidth
value|"baseWidth"
end_define

begin_define
define|#
directive|define
name|XtCBaseWidth
value|"BaseWidth"
end_define

begin_define
define|#
directive|define
name|XtNbaseHeight
value|"baseHeight"
end_define

begin_define
define|#
directive|define
name|XtCBaseHeight
value|"BaseHeight"
end_define

begin_define
define|#
directive|define
name|XtNwinGravity
value|"winGravity"
end_define

begin_define
define|#
directive|define
name|XtCWinGravity
value|"WinGravity"
end_define

begin_define
define|#
directive|define
name|XtNminWidth
value|"minWidth"
end_define

begin_define
define|#
directive|define
name|XtCMinWidth
value|"MinWidth"
end_define

begin_define
define|#
directive|define
name|XtNminHeight
value|"minHeight"
end_define

begin_define
define|#
directive|define
name|XtCMinHeight
value|"MinHeight"
end_define

begin_define
define|#
directive|define
name|XtNmaxWidth
value|"maxWidth"
end_define

begin_define
define|#
directive|define
name|XtCMaxWidth
value|"MaxWidth"
end_define

begin_define
define|#
directive|define
name|XtNmaxHeight
value|"maxHeight"
end_define

begin_define
define|#
directive|define
name|XtCMaxHeight
value|"MaxHeight"
end_define

begin_define
define|#
directive|define
name|XtNwidthInc
value|"widthInc"
end_define

begin_define
define|#
directive|define
name|XtCWidthInc
value|"WidthInc"
end_define

begin_define
define|#
directive|define
name|XtNheightInc
value|"heightInc"
end_define

begin_define
define|#
directive|define
name|XtCHeightInc
value|"HeightInc"
end_define

begin_define
define|#
directive|define
name|XtNminAspectY
value|"minAspectY"
end_define

begin_define
define|#
directive|define
name|XtCMinAspectY
value|"MinAspectY"
end_define

begin_define
define|#
directive|define
name|XtNmaxAspectY
value|"maxAspectY"
end_define

begin_define
define|#
directive|define
name|XtCMaxAspectY
value|"MaxAspectY"
end_define

begin_define
define|#
directive|define
name|XtNminAspectX
value|"minAspectX"
end_define

begin_define
define|#
directive|define
name|XtCMinAspectX
value|"MinAspectX"
end_define

begin_define
define|#
directive|define
name|XtNmaxAspectX
value|"maxAspectX"
end_define

begin_define
define|#
directive|define
name|XtCMaxAspectX
value|"MaxAspectX"
end_define

begin_define
define|#
directive|define
name|XtNwmTimeout
value|"wmTimeout"
end_define

begin_define
define|#
directive|define
name|XtCWmTimeout
value|"WmTimeout"
end_define

begin_define
define|#
directive|define
name|XtNwaitForWm
value|"waitforwm"
end_define

begin_define
define|#
directive|define
name|XtCWaitForWm
value|"Waitforwm"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|_XtConst_
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_XtConst_
end_define

begin_comment
comment|/**/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|_XtConst_
name|char
name|XtShellStrings
index|[]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconName
end_ifndef

begin_define
define|#
directive|define
name|XtNiconName
value|((char*)&XtShellStrings[0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconName
end_ifndef

begin_define
define|#
directive|define
name|XtCIconName
value|((char*)&XtShellStrings[9])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconPixmap
end_ifndef

begin_define
define|#
directive|define
name|XtNiconPixmap
value|((char*)&XtShellStrings[18])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconPixmap
end_ifndef

begin_define
define|#
directive|define
name|XtCIconPixmap
value|((char*)&XtShellStrings[29])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconWindow
end_ifndef

begin_define
define|#
directive|define
name|XtNiconWindow
value|((char*)&XtShellStrings[40])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconWindow
end_ifndef

begin_define
define|#
directive|define
name|XtCIconWindow
value|((char*)&XtShellStrings[51])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconMask
end_ifndef

begin_define
define|#
directive|define
name|XtNiconMask
value|((char*)&XtShellStrings[62])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconMask
end_ifndef

begin_define
define|#
directive|define
name|XtCIconMask
value|((char*)&XtShellStrings[71])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNwindowGroup
end_ifndef

begin_define
define|#
directive|define
name|XtNwindowGroup
value|((char*)&XtShellStrings[80])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCWindowGroup
end_ifndef

begin_define
define|#
directive|define
name|XtCWindowGroup
value|((char*)&XtShellStrings[92])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNvisual
end_ifndef

begin_define
define|#
directive|define
name|XtNvisual
value|((char*)&XtShellStrings[104])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCVisual
end_ifndef

begin_define
define|#
directive|define
name|XtCVisual
value|((char*)&XtShellStrings[111])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNtitleEncoding
end_ifndef

begin_define
define|#
directive|define
name|XtNtitleEncoding
value|((char*)&XtShellStrings[118])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCTitleEncoding
end_ifndef

begin_define
define|#
directive|define
name|XtCTitleEncoding
value|((char*)&XtShellStrings[132])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNsaveUnder
end_ifndef

begin_define
define|#
directive|define
name|XtNsaveUnder
value|((char*)&XtShellStrings[146])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCSaveUnder
end_ifndef

begin_define
define|#
directive|define
name|XtCSaveUnder
value|((char*)&XtShellStrings[156])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNtransient
end_ifndef

begin_define
define|#
directive|define
name|XtNtransient
value|((char*)&XtShellStrings[166])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCTransient
end_ifndef

begin_define
define|#
directive|define
name|XtCTransient
value|((char*)&XtShellStrings[176])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNoverrideRedirect
end_ifndef

begin_define
define|#
directive|define
name|XtNoverrideRedirect
value|((char*)&XtShellStrings[186])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCOverrideRedirect
end_ifndef

begin_define
define|#
directive|define
name|XtCOverrideRedirect
value|((char*)&XtShellStrings[203])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNtransientFor
end_ifndef

begin_define
define|#
directive|define
name|XtNtransientFor
value|((char*)&XtShellStrings[220])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCTransientFor
end_ifndef

begin_define
define|#
directive|define
name|XtCTransientFor
value|((char*)&XtShellStrings[233])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconNameEncoding
end_ifndef

begin_define
define|#
directive|define
name|XtNiconNameEncoding
value|((char*)&XtShellStrings[246])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconNameEncoding
end_ifndef

begin_define
define|#
directive|define
name|XtCIconNameEncoding
value|((char*)&XtShellStrings[263])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNallowShellResize
end_ifndef

begin_define
define|#
directive|define
name|XtNallowShellResize
value|((char*)&XtShellStrings[280])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCAllowShellResize
end_ifndef

begin_define
define|#
directive|define
name|XtCAllowShellResize
value|((char*)&XtShellStrings[297])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNcreatePopupChildProc
end_ifndef

begin_define
define|#
directive|define
name|XtNcreatePopupChildProc
value|((char*)&XtShellStrings[314])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCCreatePopupChildProc
end_ifndef

begin_define
define|#
directive|define
name|XtCCreatePopupChildProc
value|((char*)&XtShellStrings[335])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNtitle
end_ifndef

begin_define
define|#
directive|define
name|XtNtitle
value|((char*)&XtShellStrings[356])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCTitle
end_ifndef

begin_define
define|#
directive|define
name|XtCTitle
value|((char*)&XtShellStrings[362])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtRAtom
end_ifndef

begin_define
define|#
directive|define
name|XtRAtom
value|((char*)&XtShellStrings[368])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNargc
end_ifndef

begin_define
define|#
directive|define
name|XtNargc
value|((char*)&XtShellStrings[373])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCArgc
end_ifndef

begin_define
define|#
directive|define
name|XtCArgc
value|((char*)&XtShellStrings[378])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNargv
end_ifndef

begin_define
define|#
directive|define
name|XtNargv
value|((char*)&XtShellStrings[383])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCArgv
end_ifndef

begin_define
define|#
directive|define
name|XtCArgv
value|((char*)&XtShellStrings[388])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconX
end_ifndef

begin_define
define|#
directive|define
name|XtNiconX
value|((char*)&XtShellStrings[393])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconX
end_ifndef

begin_define
define|#
directive|define
name|XtCIconX
value|((char*)&XtShellStrings[399])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconY
end_ifndef

begin_define
define|#
directive|define
name|XtNiconY
value|((char*)&XtShellStrings[405])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconY
end_ifndef

begin_define
define|#
directive|define
name|XtCIconY
value|((char*)&XtShellStrings[411])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNinput
end_ifndef

begin_define
define|#
directive|define
name|XtNinput
value|((char*)&XtShellStrings[417])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCInput
end_ifndef

begin_define
define|#
directive|define
name|XtCInput
value|((char*)&XtShellStrings[423])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNiconic
end_ifndef

begin_define
define|#
directive|define
name|XtNiconic
value|((char*)&XtShellStrings[429])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCIconic
end_ifndef

begin_define
define|#
directive|define
name|XtCIconic
value|((char*)&XtShellStrings[436])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNinitialState
end_ifndef

begin_define
define|#
directive|define
name|XtNinitialState
value|((char*)&XtShellStrings[443])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCInitialState
end_ifndef

begin_define
define|#
directive|define
name|XtCInitialState
value|((char*)&XtShellStrings[456])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNgeometry
end_ifndef

begin_define
define|#
directive|define
name|XtNgeometry
value|((char*)&XtShellStrings[469])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCGeometry
end_ifndef

begin_define
define|#
directive|define
name|XtCGeometry
value|((char*)&XtShellStrings[478])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNbaseWidth
end_ifndef

begin_define
define|#
directive|define
name|XtNbaseWidth
value|((char*)&XtShellStrings[487])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCBaseWidth
end_ifndef

begin_define
define|#
directive|define
name|XtCBaseWidth
value|((char*)&XtShellStrings[497])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNbaseHeight
end_ifndef

begin_define
define|#
directive|define
name|XtNbaseHeight
value|((char*)&XtShellStrings[507])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCBaseHeight
end_ifndef

begin_define
define|#
directive|define
name|XtCBaseHeight
value|((char*)&XtShellStrings[518])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNwinGravity
end_ifndef

begin_define
define|#
directive|define
name|XtNwinGravity
value|((char*)&XtShellStrings[529])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCWinGravity
end_ifndef

begin_define
define|#
directive|define
name|XtCWinGravity
value|((char*)&XtShellStrings[540])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNminWidth
end_ifndef

begin_define
define|#
directive|define
name|XtNminWidth
value|((char*)&XtShellStrings[551])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMinWidth
end_ifndef

begin_define
define|#
directive|define
name|XtCMinWidth
value|((char*)&XtShellStrings[560])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNminHeight
end_ifndef

begin_define
define|#
directive|define
name|XtNminHeight
value|((char*)&XtShellStrings[569])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMinHeight
end_ifndef

begin_define
define|#
directive|define
name|XtCMinHeight
value|((char*)&XtShellStrings[579])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNmaxWidth
end_ifndef

begin_define
define|#
directive|define
name|XtNmaxWidth
value|((char*)&XtShellStrings[589])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMaxWidth
end_ifndef

begin_define
define|#
directive|define
name|XtCMaxWidth
value|((char*)&XtShellStrings[598])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNmaxHeight
end_ifndef

begin_define
define|#
directive|define
name|XtNmaxHeight
value|((char*)&XtShellStrings[607])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMaxHeight
end_ifndef

begin_define
define|#
directive|define
name|XtCMaxHeight
value|((char*)&XtShellStrings[617])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNwidthInc
end_ifndef

begin_define
define|#
directive|define
name|XtNwidthInc
value|((char*)&XtShellStrings[627])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCWidthInc
end_ifndef

begin_define
define|#
directive|define
name|XtCWidthInc
value|((char*)&XtShellStrings[636])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNheightInc
end_ifndef

begin_define
define|#
directive|define
name|XtNheightInc
value|((char*)&XtShellStrings[645])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCHeightInc
end_ifndef

begin_define
define|#
directive|define
name|XtCHeightInc
value|((char*)&XtShellStrings[655])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNminAspectY
end_ifndef

begin_define
define|#
directive|define
name|XtNminAspectY
value|((char*)&XtShellStrings[665])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMinAspectY
end_ifndef

begin_define
define|#
directive|define
name|XtCMinAspectY
value|((char*)&XtShellStrings[676])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNmaxAspectY
end_ifndef

begin_define
define|#
directive|define
name|XtNmaxAspectY
value|((char*)&XtShellStrings[687])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMaxAspectY
end_ifndef

begin_define
define|#
directive|define
name|XtCMaxAspectY
value|((char*)&XtShellStrings[698])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNminAspectX
end_ifndef

begin_define
define|#
directive|define
name|XtNminAspectX
value|((char*)&XtShellStrings[709])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMinAspectX
end_ifndef

begin_define
define|#
directive|define
name|XtCMinAspectX
value|((char*)&XtShellStrings[720])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNmaxAspectX
end_ifndef

begin_define
define|#
directive|define
name|XtNmaxAspectX
value|((char*)&XtShellStrings[731])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCMaxAspectX
end_ifndef

begin_define
define|#
directive|define
name|XtCMaxAspectX
value|((char*)&XtShellStrings[742])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNwmTimeout
end_ifndef

begin_define
define|#
directive|define
name|XtNwmTimeout
value|((char*)&XtShellStrings[753])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCWmTimeout
end_ifndef

begin_define
define|#
directive|define
name|XtCWmTimeout
value|((char*)&XtShellStrings[763])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtNwaitForWm
end_ifndef

begin_define
define|#
directive|define
name|XtNwaitForWm
value|((char*)&XtShellStrings[773])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XtCWaitForWm
end_ifndef

begin_define
define|#
directive|define
name|XtCWaitForWm
value|((char*)&XtShellStrings[783])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|_XtConst_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Class record constants */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_ShellClassRec
modifier|*
name|ShellWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_OverrideShellClassRec
modifier|*
name|OverrideShellWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_WMShellClassRec
modifier|*
name|WMShellWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TransientShellClassRec
modifier|*
name|TransientShellWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_TopLevelShellClassRec
modifier|*
name|TopLevelShellWidgetClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_ApplicationShellClassRec
modifier|*
name|ApplicationShellWidgetClass
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|SHELL
end_ifndef

begin_decl_stmt
name|externalref
name|WidgetClass
name|shellWidgetClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|WidgetClass
name|overrideShellWidgetClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|WidgetClass
name|wmShellWidgetClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|WidgetClass
name|transientShellWidgetClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|WidgetClass
name|topLevelShellWidgetClass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|externalref
name|WidgetClass
name|applicationShellWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XtShell_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

