begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<dev/rr232x/rr232x_config.h>
end_include

begin_comment
comment|/****************************************************************************  * config.c - auto-generated file  * $FreeBSD$  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<dev/rr232x/os_bsd.h>
end_include

begin_function_decl
specifier|extern
name|int
name|init_module_him_sx508x
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_vdev_raw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_partition
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_raid0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_raid1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_raid5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|init_module_jbod
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|init_config
parameter_list|(
name|void
parameter_list|)
block|{
name|init_module_him_sx508x
argument_list|()
expr_stmt|;
name|init_module_vdev_raw
argument_list|()
expr_stmt|;
name|init_module_partition
argument_list|()
expr_stmt|;
name|init_module_raid0
argument_list|()
expr_stmt|;
name|init_module_raid1
argument_list|()
expr_stmt|;
name|init_module_raid5
argument_list|()
expr_stmt|;
name|init_module_jbod
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|char
name|driver_name
index|[]
init|=
literal|"rr232x"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|driver_name_long
index|[]
init|=
literal|"RocketRAID 232x controller driver"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|driver_ver
index|[]
init|=
literal|"v1.02 ("
name|__DATE__
literal|" "
name|__TIME__
literal|")"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|osm_max_targets
init|=
literal|0xff
decl_stmt|;
end_decl_stmt

end_unit

