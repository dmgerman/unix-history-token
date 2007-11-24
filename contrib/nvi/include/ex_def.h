begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|C_SCROLL
value|0
end_define

begin_define
define|#
directive|define
name|C_BANG
value|1
end_define

begin_define
define|#
directive|define
name|C_HASH
value|2
end_define

begin_define
define|#
directive|define
name|C_SUBAGAIN
value|3
end_define

begin_define
define|#
directive|define
name|C_STAR
value|4
end_define

begin_define
define|#
directive|define
name|C_SHIFTL
value|5
end_define

begin_define
define|#
directive|define
name|C_EQUAL
value|6
end_define

begin_define
define|#
directive|define
name|C_SHIFTR
value|7
end_define

begin_define
define|#
directive|define
name|C_AT
value|8
end_define

begin_define
define|#
directive|define
name|C_APPEND
value|9
end_define

begin_define
define|#
directive|define
name|C_ABBR
value|10
end_define

begin_define
define|#
directive|define
name|C_ARGS
value|11
end_define

begin_define
define|#
directive|define
name|C_BG
value|12
end_define

begin_define
define|#
directive|define
name|C_CHANGE
value|13
end_define

begin_define
define|#
directive|define
name|C_CD
value|14
end_define

begin_define
define|#
directive|define
name|C_CHDIR
value|15
end_define

begin_define
define|#
directive|define
name|C_COPY
value|16
end_define

begin_define
define|#
directive|define
name|C_CSCOPE
value|17
end_define

begin_define
define|#
directive|define
name|C_DELETE
value|18
end_define

begin_define
define|#
directive|define
name|C_DISPLAY
value|19
end_define

begin_define
define|#
directive|define
name|C_EDIT
value|20
end_define

begin_define
define|#
directive|define
name|C_EX
value|21
end_define

begin_define
define|#
directive|define
name|C_EXUSAGE
value|22
end_define

begin_define
define|#
directive|define
name|C_FILE
value|23
end_define

begin_define
define|#
directive|define
name|C_FG
value|24
end_define

begin_define
define|#
directive|define
name|C_GLOBAL
value|25
end_define

begin_define
define|#
directive|define
name|C_HELP
value|26
end_define

begin_define
define|#
directive|define
name|C_INSERT
value|27
end_define

begin_define
define|#
directive|define
name|C_JOIN
value|28
end_define

begin_define
define|#
directive|define
name|C_K
value|29
end_define

begin_define
define|#
directive|define
name|C_LIST
value|30
end_define

begin_define
define|#
directive|define
name|C_MOVE
value|31
end_define

begin_define
define|#
directive|define
name|C_MARK
value|32
end_define

begin_define
define|#
directive|define
name|C_MAP
value|33
end_define

begin_define
define|#
directive|define
name|C_MKEXRC
value|34
end_define

begin_define
define|#
directive|define
name|C_NEXT
value|35
end_define

begin_define
define|#
directive|define
name|C_NUMBER
value|36
end_define

begin_define
define|#
directive|define
name|C_OPEN
value|37
end_define

begin_define
define|#
directive|define
name|C_PRINT
value|38
end_define

begin_define
define|#
directive|define
name|C_PERLCMD
value|39
end_define

begin_define
define|#
directive|define
name|C_PERLDOCMD
value|40
end_define

begin_define
define|#
directive|define
name|C_PRESERVE
value|41
end_define

begin_define
define|#
directive|define
name|C_PREVIOUS
value|42
end_define

begin_define
define|#
directive|define
name|C_PUT
value|43
end_define

begin_define
define|#
directive|define
name|C_QUIT
value|44
end_define

begin_define
define|#
directive|define
name|C_READ
value|45
end_define

begin_define
define|#
directive|define
name|C_RECOVER
value|46
end_define

begin_define
define|#
directive|define
name|C_RESIZE
value|47
end_define

begin_define
define|#
directive|define
name|C_REWIND
value|48
end_define

begin_define
define|#
directive|define
name|C_RTAG
value|49
end_define

begin_define
define|#
directive|define
name|C_SUBSTITUTE
value|50
end_define

begin_define
define|#
directive|define
name|C_SCRIPT
value|51
end_define

begin_define
define|#
directive|define
name|C_SET
value|52
end_define

begin_define
define|#
directive|define
name|C_SHELL
value|53
end_define

begin_define
define|#
directive|define
name|C_SOURCE
value|54
end_define

begin_define
define|#
directive|define
name|C_STOP
value|55
end_define

begin_define
define|#
directive|define
name|C_SUSPEND
value|56
end_define

begin_define
define|#
directive|define
name|C_T
value|57
end_define

begin_define
define|#
directive|define
name|C_TAG
value|58
end_define

begin_define
define|#
directive|define
name|C_TAGNEXT
value|59
end_define

begin_define
define|#
directive|define
name|C_TAGPOP
value|60
end_define

begin_define
define|#
directive|define
name|C_TAGPREV
value|61
end_define

begin_define
define|#
directive|define
name|C_TAGTOP
value|62
end_define

begin_define
define|#
directive|define
name|C_TCLCMD
value|63
end_define

begin_define
define|#
directive|define
name|C_UNDO
value|64
end_define

begin_define
define|#
directive|define
name|C_UNABBREVIATE
value|65
end_define

begin_define
define|#
directive|define
name|C_UNMAP
value|66
end_define

begin_define
define|#
directive|define
name|C_V
value|67
end_define

begin_define
define|#
directive|define
name|C_VERSION
value|68
end_define

begin_define
define|#
directive|define
name|C_VISUAL_EX
value|69
end_define

begin_define
define|#
directive|define
name|C_VISUAL_VI
value|70
end_define

begin_define
define|#
directive|define
name|C_VIUSAGE
value|71
end_define

begin_define
define|#
directive|define
name|C_WRITE
value|72
end_define

begin_define
define|#
directive|define
name|C_WN
value|73
end_define

begin_define
define|#
directive|define
name|C_WQ
value|74
end_define

begin_define
define|#
directive|define
name|C_XIT
value|75
end_define

begin_define
define|#
directive|define
name|C_YANK
value|76
end_define

begin_define
define|#
directive|define
name|C_Z
value|77
end_define

begin_define
define|#
directive|define
name|C_SUBTILDE
value|78
end_define

end_unit

