begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/xebec/Attic/sets.h,v $ */
end_comment

begin_define
define|#
directive|define
name|MAXEVENTS
value|200
end_define

begin_define
define|#
directive|define
name|MAXSTATES
value|200
end_define

begin_define
define|#
directive|define
name|STATESET
value|10
end_define

begin_define
define|#
directive|define
name|EVENTSET
value|5
end_define

begin_define
define|#
directive|define
name|OBJ_ITEM
value|2
end_define

begin_define
define|#
directive|define
name|OBJ_SET
value|3
end_define

begin_struct
struct|struct
name|Object
block|{
name|unsigned
name|char
name|obj_kind
decl_stmt|;
name|unsigned
name|char
name|obj_type
decl_stmt|;
comment|/* state or event */
name|char
modifier|*
name|obj_name
decl_stmt|;
name|char
modifier|*
name|obj_struc
decl_stmt|;
name|int
name|obj_number
decl_stmt|;
name|struct
name|Object
modifier|*
name|obj_members
decl_stmt|;
comment|/* must be null for kind==item */
comment|/* for the tree */
name|struct
name|Object
modifier|*
name|obj_left
decl_stmt|;
name|struct
name|Object
modifier|*
name|obj_right
decl_stmt|;
name|struct
name|Object
modifier|*
name|obj_parent
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Noname
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OBJ_NAME
parameter_list|(
name|o
parameter_list|)
value|(((o)->obj_name)?(o)->obj_name:Noname)
end_define

begin_decl_stmt
specifier|extern
name|int
name|Nevents
decl_stmt|,
name|Nstates
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Eventshift
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Object
modifier|*
name|CurrentEvent
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|Object
modifier|*
name|Lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|Object
modifier|*
name|defineset
parameter_list|()
function_decl|;
end_function_decl

end_unit

