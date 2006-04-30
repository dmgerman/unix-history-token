begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2000 Hans Reiser  * See README for licensing and copyright details  *   * Ported to FreeBSD by Jean-Sébastien Pédron<jspedron@club-internet.fr>  *   * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<gnu/fs/reiserfs/reiserfs_fs.h>
end_include

begin_comment
comment|/* -------------------------------------------------------------------  * Stat data functions  * -------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|int
name|sd_bytes_number
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|item_operations
name|stat_data_ops
init|=
block|{
operator|.
name|bytes_number
operator|=
name|sd_bytes_number
block|,
comment|//.decrement_key     = sd_decrement_key,
comment|//.is_left_mergeable = sd_is_left_mergeable,
comment|//.print_item        = sd_print_item,
comment|//.check_item        = sd_check_item,
comment|//.create_vi         = sd_create_vi,
comment|//.check_left        = sd_check_left,
comment|//.check_right       = sd_check_right,
comment|//.part_size         = sd_part_size,
comment|//.unit_num          = sd_unit_num,
comment|//.print_vi          = sd_print_vi
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -------------------------------------------------------------------  * Direct item functions  * -------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|int
name|direct_bytes_number
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
block|{
return|return
operator|(
name|ih_item_len
argument_list|(
name|ih
argument_list|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|item_operations
name|direct_ops
init|=
block|{
operator|.
name|bytes_number
operator|=
name|direct_bytes_number
block|,
comment|//.decrement_key     = direct_decrement_key,
comment|//.is_left_mergeable = direct_is_left_mergeable,
comment|//.print_item        = direct_print_item,
comment|//.check_item        = direct_check_item,
comment|//.create_vi         = direct_create_vi,
comment|//.check_left        = direct_check_left,
comment|//.check_right       = direct_check_right,
comment|//.part_size         = direct_part_size,
comment|//.unit_num          = direct_unit_num,
comment|//.print_vi          = direct_print_vi
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -------------------------------------------------------------------  * Indirect item functions  * -------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|int
name|indirect_bytes_number
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
block|{
return|return
operator|(
name|ih_item_len
argument_list|(
name|ih
argument_list|)
operator|/
name|UNFM_P_SIZE
operator|*
name|block_size
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|item_operations
name|indirect_ops
init|=
block|{
operator|.
name|bytes_number
operator|=
name|indirect_bytes_number
block|,
comment|//.decrement_key     = indirect_decrement_key,
comment|//.is_left_mergeable = indirect_is_left_mergeable,
comment|//.print_item        = indirect_print_item,
comment|//.check_item        = indirect_check_item,
comment|//.create_vi         = indirect_create_vi,
comment|//.check_left        = indirect_check_left,
comment|//.check_right       = indirect_check_right,
comment|//.part_size         = indirect_part_size,
comment|//.unit_num          = indirect_unit_num,
comment|//.print_vi          = indirect_print_vi
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -------------------------------------------------------------------  * Direntry functions  * -------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|int
name|direntry_bytes_number
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
block|{
name|reiserfs_log
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"bytes number is asked for direntry\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|item_operations
name|direntry_ops
init|=
block|{
operator|.
name|bytes_number
operator|=
name|direntry_bytes_number
block|,
comment|//.decrement_key     = direntry_decrement_key,
comment|//.is_left_mergeable = direntry_is_left_mergeable,
comment|//.print_item        = direntry_print_item,
comment|//.check_item        = direntry_check_item,
comment|//.create_vi         = direntry_create_vi,
comment|//.check_left        = direntry_check_left,
comment|//.check_right       = direntry_check_right,
comment|//.part_size         = direntry_part_size,
comment|//.unit_num          = direntry_unit_num,
comment|//.print_vi          = direntry_print_vi
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -------------------------------------------------------------------  * Error catching functions to catch errors caused by incorrect item  * types.  * -------------------------------------------------------------------*/
end_comment

begin_function
specifier|static
name|int
name|errcatch_bytes_number
parameter_list|(
name|struct
name|item_head
modifier|*
name|ih
parameter_list|,
name|int
name|block_size
parameter_list|)
block|{
name|reiserfs_log
argument_list|(
name|LOG_WARNING
argument_list|,
literal|"invalid item type observed, run fsck ASAP"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|item_operations
name|errcatch_ops
init|=
block|{
name|errcatch_bytes_number
block|,
comment|//errcatch_decrement_key,
comment|//errcatch_is_left_mergeable,
comment|//errcatch_print_item,
comment|//errcatch_check_item,
comment|//errcatch_create_vi,
comment|//errcatch_check_left,
comment|//errcatch_check_right,
comment|//errcatch_part_size,
comment|//errcatch_unit_num,
comment|//errcatch_print_vi
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
operator|(
name|TYPE_STAT_DATA
operator|==
literal|0
operator|&&
name|TYPE_INDIRECT
operator|==
literal|1
operator|&&
expr|\
name|TYPE_DIRECT
operator|==
literal|2
operator|&&
name|TYPE_DIRENTRY
operator|==
literal|3
operator|)
end_if

begin_error
error|#
directive|error
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|struct
name|item_operations
modifier|*
name|item_ops
index|[
name|TYPE_ANY
operator|+
literal|1
index|]
init|=
block|{
operator|&
name|stat_data_ops
block|,
operator|&
name|indirect_ops
block|,
operator|&
name|direct_ops
block|,
operator|&
name|direntry_ops
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
operator|&
name|errcatch_ops
comment|/* This is to catch errors with invalid type (15th 			 entry for TYPE_ANY) */
block|}
decl_stmt|;
end_decl_stmt

end_unit

