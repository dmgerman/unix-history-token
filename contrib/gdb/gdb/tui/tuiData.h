begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TUI_DATA_H
end_ifndef

begin_define
define|#
directive|define
name|TUI_DATA_H
end_define

begin_comment
comment|/* Constant definitions */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TAB_LEN
value|8
end_define

begin_define
define|#
directive|define
name|NO_SRC_STRING
value|"[ No Source Available ]"
end_define

begin_define
define|#
directive|define
name|NO_DISASSEM_STRING
value|"[ No Assembly Available ]"
end_define

begin_define
define|#
directive|define
name|NO_REGS_STRING
value|"[ Register Values Unavailable ]"
end_define

begin_define
define|#
directive|define
name|NO_DATA_STRING
value|"[ No Data Values Displayed ]"
end_define

begin_define
define|#
directive|define
name|MAX_CONTENT_COUNT
value|100
end_define

begin_define
define|#
directive|define
name|SRC_NAME
value|"SRC"
end_define

begin_define
define|#
directive|define
name|CMD_NAME
value|"CMD"
end_define

begin_define
define|#
directive|define
name|DATA_NAME
value|"REGS"
end_define

begin_define
define|#
directive|define
name|DISASSEM_NAME
value|"ASM"
end_define

begin_define
define|#
directive|define
name|TUI_NULL_STR
value|""
end_define

begin_define
define|#
directive|define
name|DEFAULT_HISTORY_COUNT
value|25
end_define

begin_define
define|#
directive|define
name|BOX_WINDOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DONT_BOX_WINDOW
value|FALSE
end_define

begin_define
define|#
directive|define
name|HILITE
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_HILITE
value|FALSE
end_define

begin_define
define|#
directive|define
name|WITH_LOCATOR
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_LOCATOR
value|FALSE
end_define

begin_define
define|#
directive|define
name|EMPTY_SOURCE_PROMPT
value|TRUE
end_define

begin_define
define|#
directive|define
name|NO_EMPTY_SOURCE_PROMPT
value|FALSE
end_define

begin_define
define|#
directive|define
name|UNDEFINED_ITEM
value|-1
end_define

begin_define
define|#
directive|define
name|MIN_WIN_HEIGHT
value|3
end_define

begin_define
define|#
directive|define
name|MIN_CMD_WIN_HEIGHT
value|3
end_define

begin_define
define|#
directive|define
name|FILE_PREFIX
value|"File: "
end_define

begin_define
define|#
directive|define
name|PROC_PREFIX
value|"Procedure: "
end_define

begin_define
define|#
directive|define
name|LINE_PREFIX
value|"Line: "
end_define

begin_define
define|#
directive|define
name|PC_PREFIX
value|"pc: "
end_define

begin_define
define|#
directive|define
name|TUI_FLOAT_REGS_NAME
value|"$FREGS"
end_define

begin_define
define|#
directive|define
name|TUI_FLOAT_REGS_NAME_LOWER
value|"$fregs"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_REGS_NAME
value|"$GREGS"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_REGS_NAME_LOWER
value|"$gregs"
end_define

begin_define
define|#
directive|define
name|TUI_SPECIAL_REGS_NAME
value|"$SREGS"
end_define

begin_define
define|#
directive|define
name|TUI_SPECIAL_REGS_NAME_LOWER
value|"$sregs"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_SPECIAL_REGS_NAME
value|"$REGS"
end_define

begin_define
define|#
directive|define
name|TUI_GENERAL_SPECIAL_REGS_NAME_LOWER
value|"$regs"
end_define

begin_comment
comment|/* Scroll direction enum */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FORWARD_SCROLL
block|,
name|BACKWARD_SCROLL
block|,
name|LEFT_SCROLL
block|,
name|RIGHT_SCROLL
block|}
name|TuiScrollDirection
operator|,
typedef|*
name|TuiScrollDirectionPtr
typedef|;
end_typedef

begin_comment
comment|/* General list struct */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiList
block|{
name|OpaqueList
name|list
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
name|TuiList
operator|,
typedef|*
name|TuiListPtr
typedef|;
end_typedef

begin_comment
comment|/* The kinds of layouts available */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SRC_COMMAND
block|,
name|DISASSEM_COMMAND
block|,
name|SRC_DISASSEM_COMMAND
block|,
name|SRC_DATA_COMMAND
block|,
name|DISASSEM_DATA_COMMAND
block|,
name|UNDEFINED_LAYOUT
block|}
name|TuiLayoutType
operator|,
typedef|*
name|TuiLayoutTypePtr
typedef|;
end_typedef

begin_comment
comment|/* Basic data types that can be displayed in the data window. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_TuiDataType
block|{
name|TUI_REGISTER
block|,
name|TUI_SCALAR
block|,
name|TUI_COMPLEX
block|,
name|TUI_STRUCT
block|}
name|TuiDataType
operator|,
name|TuiDataTypePtr
typedef|;
end_typedef

begin_comment
comment|/* Types of register displays */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_TuiRegisterDisplayType
block|{
name|TUI_UNDEFINED_REGS
block|,
name|TUI_GENERAL_REGS
block|,
name|TUI_SFLOAT_REGS
block|,
name|TUI_DFLOAT_REGS
block|,
name|TUI_SPECIAL_REGS
block|,
name|TUI_GENERAL_AND_SPECIAL_REGS
block|}
name|TuiRegisterDisplayType
operator|,
typedef|*
name|TuiRegisterDisplayTypePtr
typedef|;
end_typedef

begin_comment
comment|/* Structure describing source line or line address */
end_comment

begin_typedef
typedef|typedef
union|union
name|_TuiLineOrAddress
block|{
name|int
name|lineNo
decl_stmt|;
name|Opaque
name|addr
decl_stmt|;
block|}
name|TuiLineOrAddress
operator|,
typedef|*
name|TuiLineOrAddressPtr
typedef|;
end_typedef

begin_comment
comment|/* Current Layout definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiLayoutDef
block|{
name|TuiWinType
name|displayMode
decl_stmt|;
name|int
name|split
decl_stmt|;
name|TuiRegisterDisplayType
name|regsDisplayType
decl_stmt|;
name|TuiRegisterDisplayType
name|floatRegsDisplayType
decl_stmt|;
block|}
name|TuiLayoutDef
operator|,
typedef|*
name|TuiLayoutDefPtr
typedef|;
end_typedef

begin_comment
comment|/* Elements in the Source/Disassembly Window */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiSourceElement
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|TuiLineOrAddress
name|lineOrAddr
decl_stmt|;
name|int
name|isExecPoint
decl_stmt|;
name|int
name|hasBreak
decl_stmt|;
block|}
name|TuiSourceElement
operator|,
typedef|*
name|TuiSourceElementPtr
typedef|;
end_typedef

begin_comment
comment|/* Elements in the data display window content */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiDataElement
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|itemNo
decl_stmt|;
comment|/* the register number, or data display number */
name|TuiDataType
name|type
decl_stmt|;
name|Opaque
name|value
decl_stmt|;
name|int
name|highlight
decl_stmt|;
block|}
name|TuiDataElement
operator|,
typedef|*
name|TuiDataElementPtr
typedef|;
end_typedef

begin_comment
comment|/* Elements in the command window content */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiCommandElement
block|{
name|char
modifier|*
name|line
decl_stmt|;
block|}
name|TuiCommandElement
operator|,
typedef|*
name|TuiCommandElementPtr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_LOCATOR_ELEMENT_LEN
value|100
end_define

begin_comment
comment|/* Elements in the locator window content */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiLocatorElement
block|{
name|char
name|fileName
index|[
name|MAX_LOCATOR_ELEMENT_LEN
index|]
decl_stmt|;
name|char
name|procName
index|[
name|MAX_LOCATOR_ELEMENT_LEN
index|]
decl_stmt|;
name|int
name|lineNo
decl_stmt|;
name|Opaque
name|addr
decl_stmt|;
block|}
name|TuiLocatorElement
operator|,
typedef|*
name|TuiLocatorElementPtr
typedef|;
end_typedef

begin_comment
comment|/* An content element in a window */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|TuiSourceElement
name|source
decl_stmt|;
comment|/* the source elements */
name|TuiGenWinInfo
name|dataWindow
decl_stmt|;
comment|/* data display elements */
name|TuiDataElement
name|data
decl_stmt|;
comment|/* elements of dataWindow */
name|TuiCommandElement
name|command
decl_stmt|;
comment|/* command elements */
name|TuiLocatorElement
name|locator
decl_stmt|;
comment|/* locator elements */
name|char
modifier|*
name|simpleString
decl_stmt|;
comment|/* simple char based elements */
block|}
name|TuiWhichElement
operator|,
typedef|*
name|TuiWhichElementPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TuiWinElement
block|{
name|int
name|highlight
decl_stmt|;
name|TuiWhichElement
name|whichElement
decl_stmt|;
block|}
name|TuiWinElement
operator|,
typedef|*
name|TuiWinElementPtr
typedef|;
end_typedef

begin_comment
comment|/* This describes the content of the window. */
end_comment

begin_typedef
typedef|typedef
name|TuiWinElementPtr
modifier|*
name|TuiWinContent
typedef|;
end_typedef

begin_comment
comment|/* This struct defines the specific information about a data display window */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiDataInfo
block|{
name|TuiWinContent
name|dataContent
decl_stmt|;
comment|/* start of data display content */
name|int
name|dataContentCount
decl_stmt|;
name|TuiWinContent
name|regsContent
decl_stmt|;
comment|/* start of regs display content */
name|int
name|regsContentCount
decl_stmt|;
name|TuiRegisterDisplayType
name|regsDisplayType
decl_stmt|;
name|int
name|regsColumnCount
decl_stmt|;
name|int
name|displayRegs
decl_stmt|;
comment|/* Should regs be displayed at all? */
block|}
name|TuiDataInfo
operator|,
typedef|*
name|TuiDataInfoPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TuiSourceInfo
block|{
name|int
name|hasLocator
decl_stmt|;
comment|/* Does locator belongs to this window? */
name|TuiGenWinInfoPtr
name|executionInfo
decl_stmt|;
comment|/* execution information window */
name|int
name|horizontalOffset
decl_stmt|;
comment|/* used for horizontal scroll */
name|TuiLineOrAddress
name|startLineOrAddr
decl_stmt|;
block|}
name|TuiSourceInfo
operator|,
typedef|*
name|TuiSourceInfoPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TuiCommandInfo
block|{
name|int
name|curLine
decl_stmt|;
comment|/* The current line position */
name|int
name|curch
decl_stmt|;
comment|/* The current cursor position */
block|}
name|TuiCommandInfo
operator|,
typedef|*
name|TuiCommandInfoPtr
typedef|;
end_typedef

begin_comment
comment|/* This defines information about each logical window */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TuiWinInfo
block|{
name|TuiGenWinInfo
name|generic
decl_stmt|;
comment|/* general window information */
union|union
block|{
name|TuiSourceInfo
name|sourceInfo
decl_stmt|;
name|TuiDataInfo
name|dataDisplayInfo
decl_stmt|;
name|TuiCommandInfo
name|commandInfo
decl_stmt|;
name|Opaque
name|opaque
decl_stmt|;
block|}
name|detail
union|;
name|int
name|canHighlight
decl_stmt|;
comment|/* Can this window ever be highlighted? */
name|int
name|isHighlighted
decl_stmt|;
comment|/* Is this window highlighted? */
block|}
name|TuiWinInfo
operator|,
typedef|*
name|TuiWinInfoPtr
typedef|;
end_typedef

begin_comment
comment|/* MACROS (prefixed with m_) */
end_comment

begin_comment
comment|/* Testing macros */
end_comment

begin_define
define|#
directive|define
name|m_genWinPtrIsNull
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|((winInfo) == (TuiGenWinInfoPtr)NULL)
end_define

begin_define
define|#
directive|define
name|m_genWinPtrNotNull
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|((winInfo) != (TuiGenWinInfoPtr)NULL)
end_define

begin_define
define|#
directive|define
name|m_winPtrIsNull
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|((winInfo) == (TuiWinInfoPtr)NULL)
end_define

begin_define
define|#
directive|define
name|m_winPtrNotNull
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|((winInfo) != (TuiWinInfoPtr)NULL)
end_define

begin_define
define|#
directive|define
name|m_winIsSourceType
parameter_list|(
name|type
parameter_list|)
define|\
value|(type == SRC_WIN || type == DISASSEM_WIN)
end_define

begin_define
define|#
directive|define
name|m_winIsAuxillary
parameter_list|(
name|winType
parameter_list|)
define|\
value|(winType> MAX_MAJOR_WINDOWS)
end_define

begin_define
define|#
directive|define
name|m_hasLocator
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|( ((winInfo) != (TuiWinInfoPtr)NULL) ? \                     (winInfo->detail.sourceInfo.hasLocator) : \                     FALSE )
end_define

begin_define
define|#
directive|define
name|m_setWinHighlightOn
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|if ((winInfo) != (TuiWinInfoPtr)NULL) \                               (winInfo)->isHighlighted = TRUE
end_define

begin_define
define|#
directive|define
name|m_setWinHighlightOff
parameter_list|(
name|winInfo
parameter_list|)
define|\
value|if ((winInfo) != (TuiWinInfoPtr)NULL) \                               (winInfo)->isHighlighted = FALSE
end_define

begin_comment
comment|/* Global Data */
end_comment

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|winList
index|[
name|MAX_MAJOR_WINDOWS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tui_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros */
end_comment

begin_define
define|#
directive|define
name|srcWin
value|winList[SRC_WIN]
end_define

begin_define
define|#
directive|define
name|disassemWin
value|winList[DISASSEM_WIN]
end_define

begin_define
define|#
directive|define
name|dataWin
value|winList[DATA_WIN]
end_define

begin_define
define|#
directive|define
name|cmdWin
value|winList[CMD_WIN]
end_define

begin_comment
comment|/* Data Manipulation Functions */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|initializeStaticData
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiGenWinInfoPtr
name|allocGenericWinInfo
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|allocWinInfo
name|PARAMS
argument_list|(
operator|(
name|TuiWinType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initGenericPart
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initWinInfo
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinContent
name|allocContent
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|TuiWinType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|addContentElements
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|initContentElement
name|PARAMS
argument_list|(
operator|(
name|TuiWinElementPtr
operator|,
name|TuiWinType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeWindow
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeAllWindows
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeWinContent
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeDataContent
name|PARAMS
argument_list|(
operator|(
name|TuiWinContent
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|freeAllSourceWinsContent
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiDelWindow
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiDelDataWindows
name|PARAMS
argument_list|(
operator|(
name|TuiWinContent
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|winByName
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|partialWinByName
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|winName
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|displayableWinContentOf
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|TuiWinElementPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|displayableWinContentAt
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|winElementHeight
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|TuiWinElementPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiLayoutType
name|currentLayout
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setCurrentLayoutTo
name|PARAMS
argument_list|(
operator|(
name|TuiLayoutType
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|termHeight
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setTermHeight
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|termWidth
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setTermWidth
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|historyLimit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setHistoryLimit
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setGenWinOrigin
name|PARAMS
argument_list|(
operator|(
name|TuiGenWinInfoPtr
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiGenWinInfoPtr
name|locatorWinInfoPtr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiGenWinInfoPtr
name|sourceExecInfoWinPtr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiGenWinInfoPtr
name|disassemExecInfoWinPtr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|nullStr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|blankStr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|locationStr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|breakStr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|breakLocationStr
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiListPtr
name|sourceWindows
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearSourceWindows
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearSourceWindowsDetail
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearWinDetail
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
name|winInfo
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiAddToSourceWindows
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiDefaultTabLen
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiSetDefaultTabLen
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|tuiWinWithFocus
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiSetWinWithFocus
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiLayoutDefPtr
name|tuiLayoutDef
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tuiWinResized
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tuiSetWinResizedTo
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|tuiNextWin
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|TuiWinInfoPtr
name|tuiPrevWin
name|PARAMS
argument_list|(
operator|(
name|TuiWinInfoPtr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TUI_DATA_H */
end_comment

end_unit

