begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  STATE.H -- definitions for parameter vectors ** **	Version: **		@(#)state.h	7.1	2/5/81 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CM_MAXST
end_ifndef

begin_define
define|#
directive|define
name|CM_MAXST
value|40
end_define

begin_comment
comment|/* maximum # of states */
end_comment

begin_comment
comment|/* the state descriptor type */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|st_stat
decl_stmt|;
comment|/* status bits, see below */
name|char
name|st_type
decl_stmt|;
comment|/* the type, see below */
union|union
block|{
struct|struct
comment|/* ST_REMOT */
block|{
name|char
name|st_proc
decl_stmt|;
comment|/* the remote process */
block|}
name|st_rem
struct|;
struct|struct
comment|/* ST_LOCAL */
block|{
name|char
name|st_funcno
decl_stmt|;
comment|/* the function number to call */
name|char
name|st_next
decl_stmt|;
comment|/* the next state */
block|}
name|st_loc
struct|;
block|}
name|st_v
union|;
block|}
name|state_t
typedef|;
end_typedef

begin_comment
comment|/* bits for st_stat */
end_comment

begin_define
define|#
directive|define
name|ST_EXTERN
value|0001
end_define

begin_comment
comment|/* can be executed by user */
end_comment

begin_comment
comment|/* values for st_type */
end_comment

begin_define
define|#
directive|define
name|ST_UNDEF
value|0
end_define

begin_comment
comment|/* undefined state */
end_comment

begin_define
define|#
directive|define
name|ST_LOCAL
value|1
end_define

begin_comment
comment|/* state exists in this proc */
end_comment

begin_define
define|#
directive|define
name|ST_REMOT
value|2
end_define

begin_comment
comment|/* state exists in another proc */
end_comment

begin_endif
endif|#
directive|endif
endif|CM_MAXST
end_endif

end_unit

