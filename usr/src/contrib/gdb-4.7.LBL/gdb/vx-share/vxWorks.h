begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* vxWorks.h - VxWorks standard definitions header */
end_comment

begin_comment
comment|/*  Copyright 1984, 1985, 1986, 1987, 1988, 1989, 1990, 1992 Free Software Foundation, Inc.      This code was donated by Wind River Systems, Inc. */
end_comment

begin_comment
comment|/* modification history -------------------- 01z,05oct90,shl  added copyright notice.                  made #endif ANSI style. 01y,28sep90,del  added I960 defines. 01x,29may90,del	 moved types to vxTypes.h 01w,09apr90,jcf  added timeout definitions. 01v,24jan90,gae  moved network configuration flags here from makefile's. 01u,01sep88,mcl  definition of INSTR dependent on processor family; added SPARC. 	   +gae  added MC680X0 and defined CPU_FAMILY. 01t,08apr89,dnw  added ifdef to prevent inclusion of vxWorks.h more than once. 01s,22jun88,dnw	 moved READ, WRITE, and UPDATE back here from ioLib.h. 01r,22apr88,gae  oops! forgot some #endif's in 01q. 01q,12apr88,gae  removed QUICK& WAIT; added STD_{IN,OUT,ERR}. 		 fixed #define's of FALSE, TRUE, etc. 		 moved READ, WRITE, and UPDATE to ioLib.h. 01p,04dec87,dnw  added undefine of MC68000 to get around Green Hills bug that 		   pre-defines MC68000. 01o,12nov87,ecs  added type ULONG. 01n,08feb86,dnw  added types INSTR, UINT, USHORT. 01m,14oct85,rdc  added BUS types. 01l,16jul85,jlf  added conditional for NULL and EOF. 01k,24jun85,rdc  installed condtional compile so we can include in 		 assembly language files.  See instructions below. 		 Added System type macro and CPU type macro. 01j,13jun85,dnw  cleaned-up, removed more obsolete stuff to wrs.h 01i,11sep84,jlf  changed name from wrs.h to vxWorks.h.  removed GLOBAL. 01h,03jun84,dnw  removed IGNORE declaration. 01g,09apr84,jlf  added MEMBER_SIZE macro. 01f,14dec83,dnw  added MSB, LSB macros 01e,17nov83,jlf  added STATUS type, for routines which return a status. 01d,13jul83,dnw  added NELEMENTS macro 01c,14May83,dnw  added OFFSET macro 01b,17Feb83,dnw  added stuff from Whitesmiths std.h 01a,15Feb83,dnw  written */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCvxWorksh
end_ifndef

begin_define
define|#
directive|define
name|INCvxWorksh
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NULL
argument_list|)
operator|||
operator|(
name|NULL
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EOF
argument_list|)
operator|||
operator|(
name|EOF
operator|!=
operator|(
operator|-
literal|1
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FALSE
argument_list|)
operator|||
operator|(
name|FALSE
operator|!=
literal|0
operator|)
end_if

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TRUE
argument_list|)
operator|||
operator|(
name|TRUE
operator|!=
literal|1
operator|)
end_if

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NONE
value|(-1)
end_define

begin_comment
comment|/* for times when NULL won't do */
end_comment

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_comment
comment|/* C string terminator */
end_comment

begin_comment
comment|/* return status values */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|ERROR
value|(-1)
end_define

begin_comment
comment|/* timeout defines */
end_comment

begin_define
define|#
directive|define
name|NO_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|WAIT_FOREVER
value|(-1)
end_define

begin_comment
comment|/* low-level I/O input, output, error fd's */
end_comment

begin_define
define|#
directive|define
name|STD_IN
value|0
end_define

begin_define
define|#
directive|define
name|STD_OUT
value|1
end_define

begin_define
define|#
directive|define
name|STD_ERR
value|2
end_define

begin_comment
comment|/* modes - must match O_RDONLY/O_WRONLY/O_RDWR in ioLib.h! */
end_comment

begin_define
define|#
directive|define
name|READ
value|0
end_define

begin_define
define|#
directive|define
name|WRITE
value|1
end_define

begin_define
define|#
directive|define
name|UPDATE
value|2
end_define

begin_comment
comment|/* SYSTEM types */
end_comment

begin_define
define|#
directive|define
name|V7
value|1
end_define

begin_comment
comment|/* ATT version 7 */
end_comment

begin_define
define|#
directive|define
name|SYS_V
value|2
end_define

begin_comment
comment|/* ATT System 5 */
end_comment

begin_define
define|#
directive|define
name|BSD_4_2
value|3
end_define

begin_comment
comment|/* Berkeley BSD 4.2 */
end_comment

begin_comment
comment|/* CPU types */
end_comment

begin_comment
comment|/* The Green Hills compiler pre-defines "MC68000"!! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MC68000
end_ifdef

begin_undef
undef|#
directive|undef
name|MC68000
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MC68000
value|1
end_define

begin_define
define|#
directive|define
name|MC68010
value|2
end_define

begin_define
define|#
directive|define
name|MC68020
value|3
end_define

begin_define
define|#
directive|define
name|MC68030
value|4
end_define

begin_define
define|#
directive|define
name|MC68040
value|5
end_define

begin_define
define|#
directive|define
name|MC680X0
value|9
end_define

begin_define
define|#
directive|define
name|SPARC
value|10
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|I960
end_ifndef

begin_define
define|#
directive|define
name|I960
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|I960KB
value|21
end_define

begin_define
define|#
directive|define
name|I960CA
value|22
end_define

begin_if
if|#
directive|if
name|CPU
operator|==
name|MC68000
operator|||
name|CPU
operator|==
name|MC68010
operator|||
name|CPU
operator|==
name|MC68020
operator|||
name|CPU
operator|==
name|MC68030
end_if

begin_define
define|#
directive|define
name|CPU_FAMILY
value|MC680X0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU==MC68000 || CPU==MC68010 || CPU==MC68020 || CPU==MC68030 */
end_comment

begin_if
if|#
directive|if
name|CPU
operator|==
name|SPARC
end_if

begin_define
define|#
directive|define
name|CPU_FAMILY
value|SPARC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU==SPARC */
end_comment

begin_if
if|#
directive|if
name|CPU
operator|==
name|I960KB
end_if

begin_define
define|#
directive|define
name|CPU_FAMILY
value|I960
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	CPU==I960KB */
end_comment

begin_if
if|#
directive|if
name|CPU
operator|==
name|I960CA
end_if

begin_define
define|#
directive|define
name|CPU_FAMILY
value|I960
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	CPU==I960CA */
end_comment

begin_comment
comment|/* BUS types */
end_comment

begin_define
define|#
directive|define
name|VME_BUS
value|1
end_define

begin_define
define|#
directive|define
name|MULTI_BUS
value|2
end_define

begin_comment
comment|/* network configuration parameters */
end_comment

begin_define
define|#
directive|define
name|INET
end_define

begin_comment
comment|/* include internet protocols */
end_comment

begin_define
define|#
directive|define
name|BSD
value|43
end_define

begin_comment
comment|/* BSD 4.3 -like OS */
end_comment

begin_define
define|#
directive|define
name|BSDDEBUG
end_define

begin_comment
comment|/* turn on debug */
end_comment

begin_define
define|#
directive|define
name|GATEWAY
end_define

begin_comment
comment|/* tables to be initialized for gateway routing */
end_comment

begin_comment
comment|/* common macros */
end_comment

begin_define
define|#
directive|define
name|MSB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xff)
end_define

begin_comment
comment|/* most signif byte of 2-byte integer */
end_comment

begin_define
define|#
directive|define
name|LSB
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_comment
comment|/* least signif byte of 2-byte integer*/
end_comment

begin_define
define|#
directive|define
name|OFFSET
parameter_list|(
name|structure
parameter_list|,
name|member
parameter_list|)
comment|/* byte offset of member in structure*/
define|\
value|((int)&(((structure *) 0) -> member))
end_define

begin_define
define|#
directive|define
name|MEMBER_SIZE
parameter_list|(
name|structure
parameter_list|,
name|member
parameter_list|)
comment|/* size of a member of a structure */
define|\
value|(sizeof (((structure *) 0) -> member))
end_define

begin_define
define|#
directive|define
name|NELEMENTS
parameter_list|(
name|array
parameter_list|)
comment|/* number of elements in an array */
define|\
value|(sizeof (array) / sizeof ((array) [0]))
end_define

begin_define
define|#
directive|define
name|FOREVER
value|for (;;)
end_define

begin_define
define|#
directive|define
name|max
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)< (y)) ? (y) : (x))
end_define

begin_define
define|#
directive|define
name|min
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)< (y)) ? (x) : (y))
end_define

begin_comment
comment|/* storage class specifier definitions */
end_comment

begin_define
define|#
directive|define
name|FAST
value|register
end_define

begin_define
define|#
directive|define
name|IMPORT
value|extern
end_define

begin_define
define|#
directive|define
name|LOCAL
value|static
end_define

begin_comment
comment|/* include typedefs - must come after CPU_FAMILY definitions above */
end_comment

begin_include
include|#
directive|include
file|"vxTypes.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCvxWorksh */
end_comment

end_unit

