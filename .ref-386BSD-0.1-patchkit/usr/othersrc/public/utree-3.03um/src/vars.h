begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      VARS.H  *      UTREE variables definitions.  *      3.01-um klin, Wed May  1 10:29:37 1991  *      3.03-um klin, Tue Feb 11 14:18:50 1992, Generic lists for variables  *                                              and file type commands  *              klin, Sat Feb 15 14:44:52 1992, Video handling and partinioning of  *                                              directory and file windows changed  *              klin, Sun Feb 23 18:45:19 1992, Keybindings and variable  *                                              AUTOSAVE added  *            e klin, Sat Apr 11 11:05:54 1992, Use colors for video attributes  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MAIN_
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid_vars
index|[]
init|=
literal|"@(#) utree 3.03e-um (klin) Apr 11 1992 vars.h"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_&& !lint */
end_comment

begin_comment
comment|/*  *      File type dependent commands are hold in a dynamically linked  *      list of struct _xlist.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_xlist
block|{
name|glist
name|list
decl_stmt|;
comment|/*  Contains filetype and pointers      */
name|char
modifier|*
name|command
decl_stmt|;
comment|/*  Command format to execute           */
name|char
modifier|*
name|comment
decl_stmt|;
comment|/*  Additional comment                  */
block|}
name|xlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XNULL
value|((xlist *) 0)
end_define

begin_comment
comment|/* The xlist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to entries in the file type command list is done  *      with macros to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|XLIST
parameter_list|(
name|p
parameter_list|)
value|(&(p)->list)
end_define

begin_define
define|#
directive|define
name|XTYPE
parameter_list|(
name|p
parameter_list|)
value|((p)->list.string)
end_define

begin_define
define|#
directive|define
name|XPREV
parameter_list|(
name|p
parameter_list|)
value|((p)->list.prev)
end_define

begin_define
define|#
directive|define
name|XNEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->list.next)
end_define

begin_define
define|#
directive|define
name|XCOMD
parameter_list|(
name|p
parameter_list|)
value|((p)->command)
end_define

begin_define
define|#
directive|define
name|XCOMM
parameter_list|(
name|p
parameter_list|)
value|((p)->comment)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MAIN_
end_ifdef

begin_decl_stmt
name|xlist
modifier|*
name|xroot
init|=
name|XNULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Root of file type command list       */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_MAIN_ */
end_comment

begin_decl_stmt
specifier|extern
name|xlist
modifier|*
name|xroot
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_ */
end_comment

begin_comment
comment|/*  *      Variables are hold in a table of struct _vlist which is  *      initialized and linked at startup. All predefined variables  *      are accessed via index into this table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_vlist
block|{
name|glist
name|list
decl_stmt|;
comment|/*  Contains variable name and pointers */
name|char
modifier|*
name|shortcut
decl_stmt|;
comment|/*  Variable short cut                  */
name|int
name|type
decl_stmt|;
comment|/*  Type of variable                    */
name|int
name|number
decl_stmt|;
comment|/*  Variable number (see below)         */
name|char
modifier|*
name|defval
decl_stmt|;
comment|/*  Default value (if defined)          */
name|char
modifier|*
name|value
decl_stmt|;
comment|/*  Variable value                      */
name|char
modifier|*
name|comment
decl_stmt|;
comment|/*  Additional comment                  */
block|}
name|vlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VNULL
value|((vlist *) 0)
end_define

begin_comment
comment|/* The vlist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Access to entries in the variable list is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|VARLST
parameter_list|(
name|n
parameter_list|)
value|(&vtable[n].list)
end_define

begin_define
define|#
directive|define
name|VARNAM
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].list.string)
end_define

begin_define
define|#
directive|define
name|VARPRV
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].list.prev)
end_define

begin_define
define|#
directive|define
name|VARNXT
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].list.next)
end_define

begin_define
define|#
directive|define
name|VARCUT
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].shortcut)
end_define

begin_define
define|#
directive|define
name|VARTYP
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].type)
end_define

begin_define
define|#
directive|define
name|VARNUM
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].number)
end_define

begin_define
define|#
directive|define
name|VARDEF
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].defval)
end_define

begin_define
define|#
directive|define
name|VARVAL
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].value)
end_define

begin_define
define|#
directive|define
name|VARCOM
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].comment)
end_define

begin_comment
comment|/* Assign vtable entry to vlist pointer. Check if variable is set       */
end_comment

begin_define
define|#
directive|define
name|VARTAB
parameter_list|(
name|n
parameter_list|)
value|(&vtable[n])
end_define

begin_define
define|#
directive|define
name|VARSET
parameter_list|(
name|n
parameter_list|)
value|(vtable[n].value)
end_define

begin_comment
comment|/*  *      The same macros for access via pointers.  */
end_comment

begin_define
define|#
directive|define
name|VLIST
parameter_list|(
name|p
parameter_list|)
value|(&(p)->list)
end_define

begin_define
define|#
directive|define
name|VNAME
parameter_list|(
name|p
parameter_list|)
value|((p)->list.string)
end_define

begin_define
define|#
directive|define
name|VPREV
parameter_list|(
name|p
parameter_list|)
value|((p)->list.prev)
end_define

begin_define
define|#
directive|define
name|VNEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->list.next)
end_define

begin_define
define|#
directive|define
name|VSCUT
parameter_list|(
name|p
parameter_list|)
value|((p)->shortcut)
end_define

begin_define
define|#
directive|define
name|VTYPE
parameter_list|(
name|p
parameter_list|)
value|((p)->type)
end_define

begin_define
define|#
directive|define
name|VNUMB
parameter_list|(
name|p
parameter_list|)
value|((p)->number)
end_define

begin_define
define|#
directive|define
name|VDFLT
parameter_list|(
name|p
parameter_list|)
value|((p)->defval)
end_define

begin_define
define|#
directive|define
name|VVALE
parameter_list|(
name|p
parameter_list|)
value|((p)->value)
end_define

begin_define
define|#
directive|define
name|VCOMM
parameter_list|(
name|p
parameter_list|)
value|((p)->comment)
end_define

begin_comment
comment|/* Flag values for variables/commands settings                          */
end_comment

begin_define
define|#
directive|define
name|VC_TST
value|0
end_define

begin_comment
comment|/* Test only. Don't set                 */
end_comment

begin_define
define|#
directive|define
name|VC_SET
value|1
end_define

begin_comment
comment|/* Set but don't effect change flag     */
end_comment

begin_define
define|#
directive|define
name|VC_CHG
value|2
end_define

begin_comment
comment|/* Set and affect change flag           */
end_comment

begin_comment
comment|/* Types of variables                                                   */
end_comment

begin_define
define|#
directive|define
name|VT_B
value|0
end_define

begin_comment
comment|/* Boolean type                         */
end_comment

begin_define
define|#
directive|define
name|VT_N
value|1
end_define

begin_comment
comment|/* Numerical value                      */
end_comment

begin_define
define|#
directive|define
name|VT_S
value|2
end_define

begin_comment
comment|/* General string                       */
end_comment

begin_define
define|#
directive|define
name|VT_U
value|3
end_define

begin_comment
comment|/* User tree or file command string     */
end_comment

begin_define
define|#
directive|define
name|VT_O
value|4
end_define

begin_comment
comment|/* Other user defined strings           */
end_comment

begin_comment
comment|/* Values for boolean variables                                         */
end_comment

begin_define
define|#
directive|define
name|VB_ON
value|((char *) 1)
end_define

begin_define
define|#
directive|define
name|VB_OFF
value|((char *) 0)
end_define

begin_comment
comment|/* Indices in variable table. See variable table below                  */
end_comment

begin_define
define|#
directive|define
name|V_BL
value|0
end_define

begin_comment
comment|/* Allow bell                           */
end_comment

begin_define
define|#
directive|define
name|V_CL
value|1
end_define

begin_comment
comment|/* Clock in echo line                   */
end_comment

begin_define
define|#
directive|define
name|V_GC
value|2
end_define

begin_comment
comment|/* Use graphic character set            */
end_comment

begin_define
define|#
directive|define
name|V_TS
value|3
end_define

begin_comment
comment|/* Use terminal scroll funcs            */
end_comment

begin_define
define|#
directive|define
name|V_ST
value|4
end_define

begin_comment
comment|/* Scan tree for changes                */
end_comment

begin_define
define|#
directive|define
name|V_WD
value|5
end_define

begin_comment
comment|/* Warn about unreadable dirs           */
end_comment

begin_define
define|#
directive|define
name|V_LS
value|6
end_define

begin_comment
comment|/* Lexical sort filelists               */
end_comment

begin_define
define|#
directive|define
name|V_AS
value|7
end_define

begin_comment
comment|/* Save definition changes              */
end_comment

begin_define
define|#
directive|define
name|V_VM
value|8
end_define

begin_comment
comment|/* Video attribute using                */
end_comment

begin_define
define|#
directive|define
name|V_TI
value|9
end_define

begin_comment
comment|/* Tree indention                       */
end_comment

begin_define
define|#
directive|define
name|V_FL
value|10
end_define

begin_comment
comment|/* File lines on tree screen            */
end_comment

begin_define
define|#
directive|define
name|V_HS
value|11
end_define

begin_comment
comment|/* Size of history list                 */
end_comment

begin_define
define|#
directive|define
name|V_SH
value|12
end_define

begin_comment
comment|/* Interaktive shell                    */
end_comment

begin_define
define|#
directive|define
name|V_ED
value|13
end_define

begin_comment
comment|/* File editor                          */
end_comment

begin_define
define|#
directive|define
name|V_EDO
value|14
end_define

begin_comment
comment|/* Editor options                       */
end_comment

begin_define
define|#
directive|define
name|V_PG
value|15
end_define

begin_comment
comment|/* File viewer/pager                    */
end_comment

begin_define
define|#
directive|define
name|V_PGO
value|16
end_define

begin_comment
comment|/* Viewer options                       */
end_comment

begin_define
define|#
directive|define
name|V_XD
value|17
end_define

begin_comment
comment|/* File hex dumper                      */
end_comment

begin_define
define|#
directive|define
name|V_XDO
value|18
end_define

begin_comment
comment|/* Hex dumper options                   */
end_comment

begin_define
define|#
directive|define
name|V_LP
value|19
end_define

begin_comment
comment|/* File printer                         */
end_comment

begin_define
define|#
directive|define
name|V_LPO
value|20
end_define

begin_comment
comment|/* Printer options                      */
end_comment

begin_define
define|#
directive|define
name|V_BK
value|21
end_define

begin_comment
comment|/* Directory backup                     */
end_comment

begin_define
define|#
directive|define
name|V_BKO
value|22
end_define

begin_comment
comment|/* Backup options                       */
end_comment

begin_define
define|#
directive|define
name|V_TC0
value|22
end_define

begin_comment
comment|/* Dummy: used for calculation only     */
end_comment

begin_define
define|#
directive|define
name|V_TC1
value|23
end_define

begin_comment
comment|/* User defined tree commands           */
end_comment

begin_define
define|#
directive|define
name|V_TC2
value|24
end_define

begin_define
define|#
directive|define
name|V_TC3
value|25
end_define

begin_define
define|#
directive|define
name|V_TC4
value|26
end_define

begin_define
define|#
directive|define
name|V_TC5
value|27
end_define

begin_define
define|#
directive|define
name|V_TC6
value|28
end_define

begin_define
define|#
directive|define
name|V_TC7
value|29
end_define

begin_define
define|#
directive|define
name|V_TC8
value|30
end_define

begin_define
define|#
directive|define
name|V_TC9
value|31
end_define

begin_define
define|#
directive|define
name|V_FC0
value|31
end_define

begin_comment
comment|/* Dummy: used for calculation only     */
end_comment

begin_define
define|#
directive|define
name|V_FC1
value|32
end_define

begin_comment
comment|/* User defined file commands           */
end_comment

begin_define
define|#
directive|define
name|V_FC2
value|33
end_define

begin_define
define|#
directive|define
name|V_FC3
value|34
end_define

begin_define
define|#
directive|define
name|V_FC4
value|35
end_define

begin_define
define|#
directive|define
name|V_FC5
value|36
end_define

begin_define
define|#
directive|define
name|V_FC6
value|37
end_define

begin_define
define|#
directive|define
name|V_FC7
value|38
end_define

begin_define
define|#
directive|define
name|V_FC8
value|39
end_define

begin_define
define|#
directive|define
name|V_FC9
value|40
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USEANSICOLORS
end_ifdef

begin_define
define|#
directive|define
name|V_UC
value|41
end_define

begin_comment
comment|/* Color setting flag */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USEANSICOLORS */
end_comment

begin_comment
comment|/*  *      Table defining default variable settings (See cmds.h).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MAIN_
end_ifdef

begin_decl_stmt
name|vlist
name|vtable
index|[]
init|=
block|{
block|{
block|{
literal|"BELL"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"BL"
block|,
name|VT_B
block|,
name|V_BL
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Allow ringing of bell"
block|}
block|,
ifdef|#
directive|ifdef
name|UTCLOCK
block|{
block|{
literal|"CLOCK"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"CL"
block|,
name|VT_B
block|,
name|V_CL
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Display/update clock"
block|}
block|,
else|#
directive|else
comment|/* !UTCLOCK */
block|{
block|{
literal|"CLOCK"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"CL"
block|,
name|VT_B
block|,
name|V_CL
block|,
name|VB_OFF
block|,
name|NULL
block|,
literal|"Display/update clock"
block|}
block|,
endif|#
directive|endif
comment|/* UTCLOCK */
block|{
block|{
literal|"GRAPHCHARS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"GC"
block|,
name|VT_B
block|,
name|V_GC
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Use graphic charset"
block|}
block|,
block|{
block|{
literal|"TERMSCROLL"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"TS"
block|,
name|VT_B
block|,
name|V_TS
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Use terminal scrolling"
block|}
block|,
block|{
block|{
literal|"SCANTREE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"ST"
block|,
name|VT_B
block|,
name|V_ST
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Scan tree for changes"
block|}
block|,
block|{
block|{
literal|"WARNDIRS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"WD"
block|,
name|VT_B
block|,
name|V_WD
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Directory warnings"
block|}
block|,
block|{
block|{
literal|"LEXSORT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"LS"
block|,
name|VT_B
block|,
name|V_LS
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Lexical sort of filelists"
block|}
block|,
block|{
block|{
literal|"AUTOSAVE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"AS"
block|,
name|VT_B
block|,
name|V_AS
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Save definition/history changes"
block|}
block|,
block|{
block|{
literal|"VIDEOMODE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"VM"
block|,
name|VT_N
block|,
name|V_VM
block|,
literal|"2"
block|,
name|NULL
block|,
literal|"Video mode setting (0..2)"
block|}
block|,
block|{
block|{
literal|"TREEINDENT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"TI"
block|,
name|VT_N
block|,
name|V_TI
block|,
literal|"9"
block|,
name|NULL
block|,
literal|"Max tree indention (3..9)"
block|}
block|,
block|{
block|{
literal|"FILELINES"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"FL"
block|,
name|VT_N
block|,
name|V_FL
block|,
literal|"3"
block|,
name|NULL
block|,
literal|"Max file lines (1..9)"
block|}
block|,
block|{
block|{
literal|"HISTSIZE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"HS"
block|,
name|VT_N
block|,
name|V_HS
block|,
literal|"22"
block|,
name|NULL
block|,
literal|"Size of history list (readonly)"
block|}
block|,
block|{
block|{
literal|"SHELL"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"SH"
block|,
name|VT_S
block|,
name|V_SH
block|,
name|SHELL
block|,
name|NULL
block|,
literal|"Shell"
block|}
block|,
block|{
block|{
literal|"EDITOR"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"ED"
block|,
name|VT_S
block|,
name|V_ED
block|,
name|EDITPRG
block|,
name|NULL
block|,
literal|"Text editor"
block|}
block|,
block|{
block|{
literal|"EDITOPTS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"EO"
block|,
name|VT_S
block|,
name|V_EDO
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Editor options"
block|}
block|,
block|{
block|{
literal|"PAGER"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"PG"
block|,
name|VT_S
block|,
name|V_PG
block|,
name|PAGEPRG
block|,
name|NULL
block|,
literal|"Text pager"
block|}
block|,
block|{
block|{
literal|"PAGEOPTS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"PO"
block|,
name|VT_S
block|,
name|V_PGO
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Pager options"
block|}
block|,
block|{
block|{
literal|"XDUMPER"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"XD"
block|,
name|VT_S
block|,
name|V_XD
block|,
name|DUMPPRG
block|,
name|NULL
block|,
literal|"Hex dumper"
block|}
block|,
block|{
block|{
literal|"XDUMPOPTS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"XO"
block|,
name|VT_S
block|,
name|V_XDO
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Dumper options"
block|}
block|,
block|{
block|{
literal|"LPRINTER"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"LP"
block|,
name|VT_S
block|,
name|V_LP
block|,
name|PRINTPRG
block|,
name|NULL
block|,
literal|"Printer command"
block|}
block|,
block|{
block|{
literal|"LPRINTOPTS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"LO"
block|,
name|VT_S
block|,
name|V_LPO
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Printer options"
block|}
block|,
ifdef|#
directive|ifdef
name|UTBCKUP
block|{
block|{
literal|"BACKUP"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"BK"
block|,
name|VT_S
block|,
name|V_BK
block|,
name|UTBCKUP
block|,
name|NULL
block|,
literal|"Backup program"
block|}
block|,
else|#
directive|else
comment|/* !UTBCKUP */
block|{
block|{
literal|"BACKUP"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"BK"
block|,
name|VT_S
block|,
name|V_BK
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Backup program"
block|}
block|,
endif|#
directive|endif
comment|/* UTBCKUP */
block|{
block|{
literal|"BACKUPOPTS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"BO"
block|,
name|VT_S
block|,
name|V_BKO
block|,
name|NULL
block|,
name|NULL
block|,
literal|"Backup options"
block|}
block|,
block|{
block|{
literal|"TREECMD1"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T1"
block|,
name|VT_U
block|,
name|V_TC1
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD2"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T2"
block|,
name|VT_U
block|,
name|V_TC2
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD3"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T3"
block|,
name|VT_U
block|,
name|V_TC3
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD4"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T4"
block|,
name|VT_U
block|,
name|V_TC4
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD5"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T5"
block|,
name|VT_U
block|,
name|V_TC5
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD6"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T6"
block|,
name|VT_U
block|,
name|V_TC6
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD7"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T7"
block|,
name|VT_U
block|,
name|V_TC7
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD8"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T8"
block|,
name|VT_U
block|,
name|V_TC8
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"TREECMD9"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"T9"
block|,
name|VT_U
block|,
name|V_TC9
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD1"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F1"
block|,
name|VT_U
block|,
name|V_FC1
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD2"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F2"
block|,
name|VT_U
block|,
name|V_FC2
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD3"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F3"
block|,
name|VT_U
block|,
name|V_FC3
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD4"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F4"
block|,
name|VT_U
block|,
name|V_FC4
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD5"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F5"
block|,
name|VT_U
block|,
name|V_FC5
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD6"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F6"
block|,
name|VT_U
block|,
name|V_FC6
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD7"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F7"
block|,
name|VT_U
block|,
name|V_FC7
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD8"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F8"
block|,
name|VT_U
block|,
name|V_FC8
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
block|{
block|{
literal|"FILECMD9"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"F9"
block|,
name|VT_U
block|,
name|V_FC9
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|,
ifdef|#
directive|ifdef
name|USEANSICOLORS
block|{
block|{
literal|"USECOLORS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
literal|"UC"
block|,
name|VT_B
block|,
name|V_UC
block|,
name|VB_ON
block|,
name|NULL
block|,
literal|"Use colors if defined"
block|}
block|,
endif|#
directive|endif
comment|/* USEANSICOLORS */
block|{
block|{
name|NULL
block|}
block|}
comment|/* End of predefined variables          */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Possible user defined variables may follow, but are not implemented  */
end_comment

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|vlist
name|vtable
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MAIN_ */
end_comment

end_unit

