begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
name|struct
name|_DeviceFont
name|DeviceFont
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Device
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|sizescale
decl_stmt|;
name|int
name|res
decl_stmt|;
name|int
name|unitwidth
decl_stmt|;
name|int
name|paperlength
decl_stmt|;
name|int
name|paperwidth
decl_stmt|;
name|int
name|X11
decl_stmt|;
name|DeviceFont
modifier|*
name|fonts
decl_stmt|;
block|}
name|Device
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|device_destroy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Device
modifier|*
name|device_load
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|DeviceFont
modifier|*
name|device_find_font
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|device_char_width
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|device_name_for_code
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|device_code_width
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|device_font_special
parameter_list|()
function_decl|;
end_function_decl

end_unit

