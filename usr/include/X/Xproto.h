begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/* $Header: Xproto.h,v 10.11 86/04/22 15:09:54 jg Rel $ */
end_comment

begin_comment
comment|/* Definitions for the X window system usually hidden by library interface */
end_comment

begin_define
define|#
directive|define
name|XFROMUSER
end_define

begin_define
define|#
directive|define
name|X_TCP_LI_PORT
value|5800
end_define

begin_comment
comment|/* add display number */
end_comment

begin_define
define|#
directive|define
name|X_TCP_BI_PORT
value|5900
end_define

begin_comment
comment|/* add display number */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XFROMUSER
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|XFROMINIT
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/tmp/X"
end_define

begin_comment
comment|/* concat display number */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|X_UNIX_PATH
value|"/dev/X"
end_define

begin_comment
comment|/* concat display number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Request structure */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIGSHORTS
end_ifdef

begin_define
define|#
directive|define
name|psizeof
parameter_list|(
name|x
parameter_list|)
value|( 2*sizeof(x) / sizeof(short) )
end_define

begin_typedef
typedef|typedef
struct|struct
name|_short_p
block|{
name|short
name|left
range|:
literal|16
decl_stmt|,
name|right
range|:
literal|16
decl_stmt|;
block|}
name|short_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ushort_p
block|{
name|unsigned
name|short
name|left
range|:
literal|16
decl_stmt|,
name|right
range|:
literal|16
decl_stmt|;
block|}
name|ushort_p
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|psizeof
value|sizeof
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_XReq
block|{
name|unsigned
name|char
name|code
decl_stmt|;
name|unsigned
name|char
name|func
decl_stmt|;
name|unsigned
name|short
name|mask
name|B16
decl_stmt|;
name|Window
name|windowId
decl_stmt|;
union|union
block|{
name|long
name|l
index|[
literal|4
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|BIGSHORTS
name|short_p
name|s
index|[
literal|4
index|]
decl_stmt|;
name|ushort_p
name|u
index|[
literal|4
index|]
decl_stmt|;
else|#
directive|else
name|short
name|s
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|short
name|u
index|[
literal|8
index|]
decl_stmt|;
endif|#
directive|endif
endif|BIGSHORTS
name|char
name|b
index|[
literal|16
index|]
decl_stmt|;
block|}
name|param
union|;
block|}
name|XReq
typedef|;
end_typedef

begin_comment
comment|/* Reply structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_XRep
block|{
name|long
name|code
decl_stmt|;
union|union
block|{
name|long
name|l
index|[
literal|5
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|BIGSHORTS
name|short_p
name|s
index|[
literal|5
index|]
decl_stmt|;
name|ushort_p
name|u
index|[
literal|5
index|]
decl_stmt|;
else|#
directive|else
name|short
name|s
index|[
literal|10
index|]
decl_stmt|;
name|unsigned
name|short
name|u
index|[
literal|10
index|]
decl_stmt|;
endif|#
directive|endif
endif|BIGSHORTS
name|char
name|b
index|[
literal|20
index|]
decl_stmt|;
block|}
name|param
union|;
block|}
name|XRep
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BIGSHORTS
end_ifdef

begin_define
define|#
directive|define
name|params0
value|param.s[0].left
end_define

begin_define
define|#
directive|define
name|params1
value|param.s[0].right
end_define

begin_define
define|#
directive|define
name|params2
value|param.s[1].left
end_define

begin_define
define|#
directive|define
name|params3
value|param.s[1].right
end_define

begin_define
define|#
directive|define
name|params4
value|param.s[2].left
end_define

begin_define
define|#
directive|define
name|params5
value|param.s[2].right
end_define

begin_define
define|#
directive|define
name|params6
value|param.s[3].left
end_define

begin_define
define|#
directive|define
name|params7
value|param.s[3].right
end_define

begin_define
define|#
directive|define
name|params8
value|param.s[4].left
end_define

begin_define
define|#
directive|define
name|params9
value|param.s[4].right
end_define

begin_define
define|#
directive|define
name|paramu0
value|param.u[0].left
end_define

begin_define
define|#
directive|define
name|paramu1
value|param.u[0].right
end_define

begin_define
define|#
directive|define
name|paramu2
value|param.u[1].left
end_define

begin_define
define|#
directive|define
name|paramu3
value|param.u[1].right
end_define

begin_define
define|#
directive|define
name|paramu4
value|param.u[2].left
end_define

begin_define
define|#
directive|define
name|paramu5
value|param.u[2].right
end_define

begin_define
define|#
directive|define
name|paramu6
value|param.u[3].left
end_define

begin_define
define|#
directive|define
name|paramu7
value|param.u[3].right
end_define

begin_define
define|#
directive|define
name|paramu8
value|param.u[4].left
end_define

begin_define
define|#
directive|define
name|paramu9
value|param.u[4].right
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|params0
value|param.s[0]
end_define

begin_define
define|#
directive|define
name|params1
value|param.s[1]
end_define

begin_define
define|#
directive|define
name|params2
value|param.s[2]
end_define

begin_define
define|#
directive|define
name|params3
value|param.s[3]
end_define

begin_define
define|#
directive|define
name|params4
value|param.s[4]
end_define

begin_define
define|#
directive|define
name|params5
value|param.s[5]
end_define

begin_define
define|#
directive|define
name|params6
value|param.s[6]
end_define

begin_define
define|#
directive|define
name|params7
value|param.s[7]
end_define

begin_define
define|#
directive|define
name|params8
value|param.s[8]
end_define

begin_define
define|#
directive|define
name|params9
value|param.s[9]
end_define

begin_define
define|#
directive|define
name|paramu0
value|param.u[0]
end_define

begin_define
define|#
directive|define
name|paramu1
value|param.u[1]
end_define

begin_define
define|#
directive|define
name|paramu2
value|param.u[2]
end_define

begin_define
define|#
directive|define
name|paramu3
value|param.u[3]
end_define

begin_define
define|#
directive|define
name|paramu4
value|param.u[4]
end_define

begin_define
define|#
directive|define
name|paramu5
value|param.u[5]
end_define

begin_define
define|#
directive|define
name|paramu6
value|param.u[6]
end_define

begin_define
define|#
directive|define
name|paramu7
value|param.u[7]
end_define

begin_define
define|#
directive|define
name|paramu8
value|param.u[8]
end_define

begin_define
define|#
directive|define
name|paramu9
value|param.u[9]
end_define

begin_endif
endif|#
directive|endif
endif|BIGSHORTS
end_endif

begin_comment
comment|/* Reply codes */
end_comment

begin_define
define|#
directive|define
name|X_Reply
value|0
end_define

begin_comment
comment|/* Normal reply */
end_comment

begin_define
define|#
directive|define
name|X_Error
value|-1
end_define

begin_comment
comment|/* Error */
end_comment

begin_comment
comment|/* Request codes */
end_comment

begin_define
define|#
directive|define
name|X_CreateWindow
value|1
end_define

begin_define
define|#
directive|define
name|X_CreateTransparency
value|2
end_define

begin_define
define|#
directive|define
name|X_DestroyWindow
value|3
end_define

begin_define
define|#
directive|define
name|X_DestroySubwindows
value|4
end_define

begin_define
define|#
directive|define
name|X_MapWindow
value|5
end_define

begin_define
define|#
directive|define
name|X_MapSubwindows
value|6
end_define

begin_define
define|#
directive|define
name|X_UnmapWindow
value|7
end_define

begin_define
define|#
directive|define
name|X_UnmapSubwindows
value|8
end_define

begin_define
define|#
directive|define
name|X_UnmapTransparent
value|9
end_define

begin_define
define|#
directive|define
name|X_RaiseWindow
value|10
end_define

begin_define
define|#
directive|define
name|X_LowerWindow
value|11
end_define

begin_define
define|#
directive|define
name|X_CircWindowUp
value|12
end_define

begin_define
define|#
directive|define
name|X_MoveWindow
value|13
end_define

begin_define
define|#
directive|define
name|X_ChangeWindow
value|14
end_define

begin_define
define|#
directive|define
name|X_ConfigureWindow
value|15
end_define

begin_define
define|#
directive|define
name|X_ChangeBackground
value|16
end_define

begin_define
define|#
directive|define
name|X_ChangeBorder
value|17
end_define

begin_define
define|#
directive|define
name|X_TileMode
value|18
end_define

begin_define
define|#
directive|define
name|X_ClipMode
value|19
end_define

begin_define
define|#
directive|define
name|X_QueryWindow
value|20
end_define

begin_define
define|#
directive|define
name|X_StoreName
value|21
end_define

begin_define
define|#
directive|define
name|X_FetchName
value|22
end_define

begin_define
define|#
directive|define
name|X_SetIconWindow
value|23
end_define

begin_define
define|#
directive|define
name|X_SetResizeHint
value|24
end_define

begin_define
define|#
directive|define
name|X_GetResizeHint
value|25
end_define

begin_define
define|#
directive|define
name|X_DefineCursor
value|26
end_define

begin_define
define|#
directive|define
name|X_SelectInput
value|27
end_define

begin_define
define|#
directive|define
name|X_GrabMouse
value|28
end_define

begin_define
define|#
directive|define
name|X_GrabButton
value|29
end_define

begin_define
define|#
directive|define
name|X_QueryMouse
value|30
end_define

begin_define
define|#
directive|define
name|X_InterpretLocator
value|31
end_define

begin_define
define|#
directive|define
name|X_WarpMouse
value|32
end_define

begin_define
define|#
directive|define
name|X_FocusKeyboard
value|33
end_define

begin_define
define|#
directive|define
name|X_CircWindowDown
value|34
end_define

begin_define
define|#
directive|define
name|X_QueryTree
value|35
end_define

begin_define
define|#
directive|define
name|X_Clear
value|40
end_define

begin_define
define|#
directive|define
name|X_PixFill
value|41
end_define

begin_define
define|#
directive|define
name|X_TileFill
value|42
end_define

begin_define
define|#
directive|define
name|X_PixmapPut
value|43
end_define

begin_define
define|#
directive|define
name|X_PixmapBitsPut
value|44
end_define

begin_define
define|#
directive|define
name|X_BitmapBitsPut
value|45
end_define

begin_define
define|#
directive|define
name|X_CopyArea
value|46
end_define

begin_define
define|#
directive|define
name|X_Text
value|47
end_define

begin_define
define|#
directive|define
name|X_TextMask
value|48
end_define

begin_define
define|#
directive|define
name|X_Line
value|49
end_define

begin_define
define|#
directive|define
name|X_Draw
value|50
end_define

begin_define
define|#
directive|define
name|X_DrawFilled
value|51
end_define

begin_define
define|#
directive|define
name|X_PixmapSave
value|52
end_define

begin_define
define|#
directive|define
name|X_PixmapGet
value|53
end_define

begin_define
define|#
directive|define
name|X_StippleFill
value|54
end_define

begin_define
define|#
directive|define
name|X_SetUp
value|80
end_define

begin_define
define|#
directive|define
name|X_UngrabMouse
value|81
end_define

begin_define
define|#
directive|define
name|X_UngrabButton
value|82
end_define

begin_define
define|#
directive|define
name|X_GetColor
value|83
end_define

begin_define
define|#
directive|define
name|X_GetColorCells
value|84
end_define

begin_define
define|#
directive|define
name|X_FreeColors
value|85
end_define

begin_define
define|#
directive|define
name|X_StoreColors
value|86
end_define

begin_define
define|#
directive|define
name|X_QueryColor
value|87
end_define

begin_define
define|#
directive|define
name|X_GetFont
value|88
end_define

begin_define
define|#
directive|define
name|X_FreeFont
value|89
end_define

begin_define
define|#
directive|define
name|X_QueryFont
value|90
end_define

begin_define
define|#
directive|define
name|X_CharWidths
value|91
end_define

begin_define
define|#
directive|define
name|X_StringWidth
value|92
end_define

begin_define
define|#
directive|define
name|X_FontWidths
value|93
end_define

begin_define
define|#
directive|define
name|X_StoreBitmap
value|94
end_define

begin_define
define|#
directive|define
name|X_FreeBitmap
value|95
end_define

begin_define
define|#
directive|define
name|X_CharBitmap
value|96
end_define

begin_define
define|#
directive|define
name|X_StorePixmap
value|97
end_define

begin_define
define|#
directive|define
name|X_FreePixmap
value|98
end_define

begin_define
define|#
directive|define
name|X_MakePixmap
value|99
end_define

begin_define
define|#
directive|define
name|X_QueryShape
value|100
end_define

begin_define
define|#
directive|define
name|X_StoreCursor
value|101
end_define

begin_define
define|#
directive|define
name|X_FreeCursor
value|102
end_define

begin_define
define|#
directive|define
name|X_MouseControl
value|103
end_define

begin_define
define|#
directive|define
name|X_FeepControl
value|104
end_define

begin_define
define|#
directive|define
name|X_Feep
value|105
end_define

begin_define
define|#
directive|define
name|X_ShiftLock
value|106
end_define

begin_define
define|#
directive|define
name|X_KeyClick
value|107
end_define

begin_define
define|#
directive|define
name|X_AutoRepeat
value|108
end_define

begin_define
define|#
directive|define
name|X_ScreenSaver
value|109
end_define

begin_define
define|#
directive|define
name|X_StoreBytes
value|110
end_define

begin_define
define|#
directive|define
name|X_FetchBytes
value|111
end_define

begin_define
define|#
directive|define
name|X_RotateCuts
value|112
end_define

begin_define
define|#
directive|define
name|X_AddHost
value|113
end_define

begin_define
define|#
directive|define
name|X_RemoveHost
value|114
end_define

begin_define
define|#
directive|define
name|X_GetHosts
value|115
end_define

begin_define
define|#
directive|define
name|X_GrabServer
value|116
end_define

begin_define
define|#
directive|define
name|X_UngrabServer
value|117
end_define

begin_define
define|#
directive|define
name|X_LookupColor
value|118
end_define

begin_define
define|#
directive|define
name|X_AppendBytes
value|119
end_define

end_unit

