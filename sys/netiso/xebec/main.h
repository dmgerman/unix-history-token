begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/xebec/Attic/main.h,v $ */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|LINELEN
value|2350
end_define

begin_comment
comment|/* approx limit on token size for C compiler 	 * which matters for the purpose of debugging (astring.c...) 	 */
end_comment

begin_define
define|#
directive|define
name|MSIZE
value|4000
end_define

begin_define
define|#
directive|define
name|DEBUGFILE
value|"astring.c"
end_define

begin_define
define|#
directive|define
name|ACTFILE
value|"driver.c"
end_define

begin_define
define|#
directive|define
name|EVENTFILE_H
value|"events.h"
end_define

begin_define
define|#
directive|define
name|STATEFILE
value|"states.h"
end_define

begin_define
define|#
directive|define
name|STATEVALFILE
value|"states.init"
end_define

begin_define
define|#
directive|define
name|EV_PREFIX
value|"EV_"
end_define

begin_define
define|#
directive|define
name|ST_PREFIX
value|"ST_"
end_define

begin_define
define|#
directive|define
name|PCBNAME
value|"_PCB_"
end_define

begin_decl_stmt
specifier|extern
name|char
name|kerneldirname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|protocol
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|synonyms
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EVENT_SYN
value|0
end_define

begin_define
define|#
directive|define
name|PCB_SYN
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|transno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|print_trans
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|stash
parameter_list|()
function_decl|;
end_function_decl

end_unit

