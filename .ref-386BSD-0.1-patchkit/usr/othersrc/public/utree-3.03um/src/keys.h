begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *      KEYS.H  *      UTREE key definitions.  *      3.01-um klin, Sat Apr 20 11:02:33 1991  *      3.02-um klin, Sun Nov 10 19:46:21 1991, Function key handling changed  *              klin, Sun Nov 24 12:12:13 1991, Extensions for XENIX reported  *                                              by Rolf Gebhardt (RG 11/22/91)  *      3.03-um klin, Sat Feb 11 19:52:04 1992, Line editor extended  *              klin, Sun Feb 23 17:34:01 1992, Key handling and key bindings  *            a klin, Sun Mar 15 19:08:25 1992, Bug fix in handling 8 bit chars  *  *      Copyright (c) 1991/92 by Peter Klingebiel& UNIX Magazin Muenchen.  *      For copying and distribution information see the file COPYRIGHT.  */
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
name|sccsid_keys
index|[]
init|=
literal|"@(#) utree 3.03a-um (klin) Mar 15 1992 keys.h"
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
comment|/*  *      Return values from getline() and editline()  */
end_comment

begin_define
define|#
directive|define
name|IN_OK
value|1
end_define

begin_comment
comment|/* Input not empty and ok               */
end_comment

begin_define
define|#
directive|define
name|IN_NUL
value|0
end_define

begin_comment
comment|/* Input empty                          */
end_comment

begin_define
define|#
directive|define
name|IN_INT
value|-1
end_define

begin_comment
comment|/* Interrupt on input                   */
end_comment

begin_define
define|#
directive|define
name|IN_EOF
value|-2
end_define

begin_comment
comment|/* EOF on input                         */
end_comment

begin_define
define|#
directive|define
name|IN_HLP
value|-3
end_define

begin_comment
comment|/* Help key on input                    */
end_comment

begin_define
define|#
directive|define
name|IN_NXT
value|-4
end_define

begin_comment
comment|/* Next key on input                    */
end_comment

begin_define
define|#
directive|define
name|IN_PRV
value|-5
end_define

begin_comment
comment|/* Previous key on input                */
end_comment

begin_define
define|#
directive|define
name|IN_SIZ
value|-6
end_define

begin_comment
comment|/* Screen size changed                  */
end_comment

begin_comment
comment|/*  *      Key symbols and initial bindings = return values from getkey()  */
end_comment

begin_define
define|#
directive|define
name|K_SEL
value|0x000a
end_define

begin_comment
comment|/* Select/accept line = NEWLINE         */
end_comment

begin_define
define|#
directive|define
name|K_FORW
value|0xff10
end_define

begin_comment
comment|/* Forward character/file/directory     */
end_comment

begin_define
define|#
directive|define
name|K_BACK
value|0xff11
end_define

begin_comment
comment|/* Backward character/file/directory    */
end_comment

begin_define
define|#
directive|define
name|K_NEXT
value|0xff12
end_define

begin_comment
comment|/* Next listentry/file/directory        */
end_comment

begin_define
define|#
directive|define
name|K_PREV
value|0xff13
end_define

begin_comment
comment|/* Previous listentry/file/directory    */
end_comment

begin_define
define|#
directive|define
name|K_NPAG
value|0xff14
end_define

begin_comment
comment|/* Next page                            */
end_comment

begin_define
define|#
directive|define
name|K_PPAG
value|0xff15
end_define

begin_comment
comment|/* Previous page                        */
end_comment

begin_define
define|#
directive|define
name|K_HOME
value|0xff16
end_define

begin_comment
comment|/* Beginning line/files/directories     */
end_comment

begin_define
define|#
directive|define
name|K_END
value|0xff17
end_define

begin_comment
comment|/* End line/files/directories           */
end_comment

begin_define
define|#
directive|define
name|K_UP
value|0xff18
end_define

begin_comment
comment|/* Scroll up files/directories          */
end_comment

begin_define
define|#
directive|define
name|K_DOWN
value|0xff19
end_define

begin_comment
comment|/* Scroll down or delete character      */
end_comment

begin_define
define|#
directive|define
name|K_INS
value|0xff20
end_define

begin_comment
comment|/* Change to dir/toggle insert mode     */
end_comment

begin_define
define|#
directive|define
name|K_DEL
value|0xff21
end_define

begin_comment
comment|/* Change to parent/delete char back    */
end_comment

begin_define
define|#
directive|define
name|K_KILL
value|0xff22
end_define

begin_comment
comment|/* Kill line                            */
end_comment

begin_define
define|#
directive|define
name|K_MARK
value|0xff23
end_define

begin_comment
comment|/* Set mark on line/file/directory      */
end_comment

begin_define
define|#
directive|define
name|K_GOTO
value|0xff24
end_define

begin_comment
comment|/* Goto mark on line/file/directory     */
end_comment

begin_define
define|#
directive|define
name|K_TAG
value|0xff25
end_define

begin_comment
comment|/* Goto tagged dir/file or transpose    */
end_comment

begin_define
define|#
directive|define
name|K_HELP
value|0xff26
end_define

begin_comment
comment|/* Help                                 */
end_comment

begin_define
define|#
directive|define
name|K_REFR
value|0xff27
end_define

begin_comment
comment|/* Refresh                              */
end_comment

begin_define
define|#
directive|define
name|K_CANC
value|0xff28
end_define

begin_comment
comment|/* Cancel line                          */
end_comment

begin_define
define|#
directive|define
name|K_BRK
value|0xff29
end_define

begin_comment
comment|/* Break command/line                   */
end_comment

begin_define
define|#
directive|define
name|K_EOF
value|0xff30
end_define

begin_comment
comment|/* EOF                                  */
end_comment

begin_define
define|#
directive|define
name|K_STR
value|0xffe0
end_define

begin_comment
comment|/* Insert string                        */
end_comment

begin_define
define|#
directive|define
name|K_INV
value|0xffff
end_define

begin_comment
comment|/* Invalid symbol                       */
end_comment

begin_define
define|#
directive|define
name|K_SIZE
value|0xff
end_define

begin_comment
comment|/* Screen size changed                  */
end_comment

begin_comment
comment|/*  *      All key symbol definitions are hold in an array of record type  *      struct _kname to permit dynamic key bindings.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ksym
typedef|;
end_typedef

begin_comment
comment|/* Type of key symbol                   */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|kchar
typedef|;
end_typedef

begin_comment
comment|/* Type of key strings                  */
end_comment

begin_define
define|#
directive|define
name|UNULL
value|((kchar *) 0)
end_define

begin_comment
comment|/* The kchar NIL pointer                */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_kname
block|{
name|glist
name|list
decl_stmt|;
comment|/* Contains key name and pointers       */
name|ksym
name|symbol
decl_stmt|;
comment|/* Key symbol (See definitions above)   */
name|char
modifier|*
name|comment
decl_stmt|;
comment|/* Meaning of key                       */
block|}
name|kname
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_MAIN_
end_ifdef

begin_decl_stmt
name|kname
name|keynames
index|[]
init|=
block|{
block|{
block|{
literal|"SELECT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_SEL
block|,
literal|"Select/accept line"
block|}
block|,
block|{
block|{
literal|"FORWARD"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_FORW
block|,
literal|"Forward character/file/directory"
block|}
block|,
block|{
block|{
literal|"BACKWARD"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_BACK
block|,
literal|"Backward character/file/directory"
block|}
block|,
block|{
block|{
literal|"NEXT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_NEXT
block|,
literal|"Next string/file/directory"
block|}
block|,
block|{
block|{
literal|"PREVIOUS"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_PREV
block|,
literal|"Previous string/file/directory"
block|}
block|,
block|{
block|{
literal|"NEXTPAGE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_NPAG
block|,
literal|"Next page/scroll forward line"
block|}
block|,
block|{
block|{
literal|"PREVPAGE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_PPAG
block|,
literal|"Previous page/scroll backward line"
block|}
block|,
block|{
block|{
literal|"BEGIN"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_HOME
block|,
literal|"Beginning of line/files/directories"
block|}
block|,
block|{
block|{
literal|"END"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_END
block|,
literal|"End of line/files/directories"
block|}
block|,
block|{
block|{
literal|"UP"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_UP
block|,
literal|"Scroll up files/directories"
block|}
block|,
block|{
block|{
literal|"DOWN"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_DOWN
block|,
literal|"Scroll down or delete character"
block|}
block|,
block|{
block|{
literal|"INSERT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_INS
block|,
literal|"Change to dir/toggle insert mode"
block|}
block|,
block|{
block|{
literal|"DELETE"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_DEL
block|,
literal|"Change to parent/delete char backward"
block|}
block|,
block|{
block|{
literal|"KILL"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_KILL
block|,
literal|"Kill input line"
block|, }
block|,
block|{
block|{
literal|"SETMARK"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_MARK
block|,
literal|"Set mark on line/file/directory"
block|}
block|,
block|{
block|{
literal|"GOTOMARK"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_GOTO
block|,
literal|"Goto mark on line/file/directory"
block|}
block|,
block|{
block|{
literal|"GOTOTAG"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_TAG
block|,
literal|"Goto tagged dir/file or transpose"
block|}
block|,
block|{
block|{
literal|"HELP"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_HELP
block|,
literal|"Help"
block|}
block|,
block|{
block|{
literal|"REFRESH"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_REFR
block|,
literal|"Refresh screen/input line"
block|}
block|,
block|{
block|{
literal|"CANCEL"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_CANC
block|,
literal|"Delete input line"
block|}
block|,
block|{
block|{
literal|"BREAK"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_BRK
block|,
literal|"Break command/line"
block|}
block|,
block|{
block|{
literal|"EXIT"
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_EOF
block|,
literal|"Exit"
block|}
block|,
block|{
block|{
literal|"\""
block|,
name|GNULL
block|,
name|GNULL
block|}
block|,
name|K_STR
block|,
literal|"Insert string"
block|}
block|,
block|{
block|{
name|NULL
block|}
block|}
comment|/* End of entries                       */
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! _MAIN_ */
end_comment

begin_decl_stmt
specifier|extern
name|kname
name|keynames
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

begin_comment
comment|/*  *      Access to entries in the keyname list is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|KNLST
parameter_list|(
name|n
parameter_list|)
value|(&keynames[n].list)
end_define

begin_define
define|#
directive|define
name|KNNAM
parameter_list|(
name|n
parameter_list|)
value|(keynames[n].list.string)
end_define

begin_define
define|#
directive|define
name|KNPRV
parameter_list|(
name|n
parameter_list|)
value|(keynames[n].list.prev)
end_define

begin_define
define|#
directive|define
name|KNNXT
parameter_list|(
name|n
parameter_list|)
value|(keynames[n].list.next)
end_define

begin_define
define|#
directive|define
name|KNSYM
parameter_list|(
name|n
parameter_list|)
value|(keynames[n].symbol)
end_define

begin_define
define|#
directive|define
name|KNCOM
parameter_list|(
name|n
parameter_list|)
value|(keynames[n].comment)
end_define

begin_comment
comment|/*  *      Key bindings are hold in a dynamically linked list of  *      record type klist. The key binding and translation list  *      is built up at startup time from default bindings and  *      user defined bindings.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_klist
block|{
name|glist
name|list
decl_stmt|;
comment|/* Contains key name and pointers       */
name|kchar
modifier|*
name|string
decl_stmt|;
comment|/* Key string                           */
name|ksym
name|symbol
decl_stmt|;
comment|/* Key symbol (See defines above)       */
name|char
modifier|*
name|insert
decl_stmt|;
comment|/* String to insert                     */
name|int
name|userdefined
decl_stmt|;
comment|/* User defined binding                 */
block|}
name|klist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KNULL
value|((klist *) 0)
end_define

begin_comment
comment|/* The klist NIL pointer                */
end_comment

begin_comment
comment|/*  *      Acces to items of klist record is done with macros  *      to hide this record and for abbreviation.  */
end_comment

begin_define
define|#
directive|define
name|KBNAM
parameter_list|(
name|p
parameter_list|)
value|((p)->list.string)
end_define

begin_define
define|#
directive|define
name|KBPRV
parameter_list|(
name|p
parameter_list|)
value|((p)->list.prev)
end_define

begin_define
define|#
directive|define
name|KBNXT
parameter_list|(
name|p
parameter_list|)
value|((p)->list.next)
end_define

begin_define
define|#
directive|define
name|KBSYM
parameter_list|(
name|p
parameter_list|)
value|((p)->symbol)
end_define

begin_define
define|#
directive|define
name|KBSTR
parameter_list|(
name|p
parameter_list|)
value|((p)->string)
end_define

begin_define
define|#
directive|define
name|KBINS
parameter_list|(
name|p
parameter_list|)
value|((p)->insert)
end_define

begin_define
define|#
directive|define
name|KBUSR
parameter_list|(
name|p
parameter_list|)
value|((p)->userdefined)
end_define

begin_comment
comment|/* Special macro for key string comparison character per character      */
end_comment

begin_define
define|#
directive|define
name|KBCHR
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|((p)->string[n])
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_MAIN_
end_ifdef

begin_decl_stmt
name|klist
modifier|*
name|kroot
init|=
name|KNULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|klist
modifier|*
name|kroot
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

