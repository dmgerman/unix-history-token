begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: cell.h,v 2.0 84/06/18 15:46:34 guido Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Definitions for linked lists of screen lines, baptized `cells'.  * (This is NOT an abstract data type!)  */
end_comment

begin_struct
struct|struct
name|cell
block|{
name|struct
name|cell
modifier|*
name|c_link
decl_stmt|;
name|node
name|c_data
decl_stmt|;
name|short
name|c_onscreen
decl_stmt|;
name|short
name|c_oldindent
decl_stmt|;
name|short
name|c_newindent
decl_stmt|;
name|short
name|c_length
decl_stmt|;
name|char
name|c_oldvhole
decl_stmt|;
name|char
name|c_newvhole
decl_stmt|;
comment|/* Yes if this line contains a `vhole' */
name|char
name|c_oldfocus
decl_stmt|;
name|char
name|c_newfocus
decl_stmt|;
comment|/* Yes if this line contains underlining */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cell
name|cell
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Cnil
value|((cell*) NULL)
end_define

begin_define
define|#
directive|define
name|Nowhere
value|(-9999)
end_define

begin_define
define|#
directive|define
name|SpaceRound
parameter_list|(
name|x
parameter_list|)
value|((indent + (x) + llength - 1) / llength)
end_define

begin_define
define|#
directive|define
name|Space
parameter_list|(
name|p
parameter_list|)
define|\
value|SpaceRound((p)->c_length + (p)->c_newindent + (p)->c_newvhole)
end_define

begin_define
define|#
directive|define
name|Oldspace
parameter_list|(
name|p
parameter_list|)
define|\
value|SpaceRound((p)->c_length + (p)->c_newindent + (p)->c_newvhole)
end_define

begin_function_decl
name|cell
modifier|*
name|replist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|cell
modifier|*
name|build
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|llength
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|winheight
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|indent
decl_stmt|;
end_decl_stmt

end_unit

