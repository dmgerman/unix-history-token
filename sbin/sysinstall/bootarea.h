begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994, Paul Richards.  *  * All rights reserved.  *  * This software may be used, modified, copied, distributed, and  * sold, in both source and binary form provided that the above  * copyright and these terms are retained, verbatim, as the first  * lines of this file.  Under no circumstances is the author  * responsible for the proper functioning of this software, nor does  * the author assume any responsibility for damages incurred with  * its use.  */
end_comment

begin_define
define|#
directive|define
name|BOOT_MAGIC
value|0xAA55
end_define

begin_define
define|#
directive|define
name|ACTIVE
value|0x80
end_define

begin_define
define|#
directive|define
name|BOOT1
value|"/usr/mdec/sdboot"
end_define

begin_define
define|#
directive|define
name|BOOT2
value|"/usr/mdec/bootsd"
end_define

begin_comment
comment|/* XXX -- calculate these, this is nasty */
end_comment

begin_define
define|#
directive|define
name|DEFFSIZE
value|1024
end_define

begin_define
define|#
directive|define
name|DEFFRAG
value|8
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|part_type
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|disk_size
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|enable_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|disable_label
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|write_bootblocks
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|build_bootblocks
parameter_list|(
name|struct
name|disklabel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|build_disklabel
parameter_list|(
name|struct
name|disklabel
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|write_bootarea
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|read_bootarea
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|bootarea
block|{
name|unsigned
name|char
name|padding
index|[
literal|2
index|]
decl_stmt|;
comment|/* force longs to be long aligned */
name|unsigned
name|char
name|bootcode
index|[
name|DOSPARTOFF
index|]
decl_stmt|;
name|struct
name|dos_partition
name|dospart
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|short
name|signature
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|part_type
block|{
name|unsigned
name|char
name|type
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

end_unit

