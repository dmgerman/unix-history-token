begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|__sFILE
block|{
name|unsigned
name|char
modifier|*
name|_p
decl_stmt|;
block|}
name|FILE
typedef|;
end_typedef

begin_decl_stmt
name|FILE
modifier|*
name|fopen
argument_list|(
specifier|const
name|char
operator|*
specifier|restrict
argument_list|,
specifier|const
name|char
operator|*
specifier|restrict
argument_list|)
asm|__asm("_" "fopen" );
name|int
name|fputc
argument_list|(
name|int
argument_list|,
name|FILE
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|fputs
argument_list|(
specifier|const
name|char
operator|*
specifier|restrict
argument_list|,
name|FILE
operator|*
specifier|restrict
argument_list|)
asm|__asm("_" "fputs" );
name|int
name|fclose
argument_list|(
name|FILE
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

