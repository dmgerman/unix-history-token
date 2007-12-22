begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* chardata.h     Interface to some helper routines used to accumulate and check text    and attribute content. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XML_CHARDATA_H
end_ifndef

begin_define
define|#
directive|define
name|XML_CHARDATA_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|XML_VERSION
end_ifndef

begin_include
include|#
directive|include
file|"expat.h"
end_include

begin_comment
comment|/* need XML_Char */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|count
decl_stmt|;
comment|/* # of chars,< 0 if not set */
name|XML_Char
name|data
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|CharData
typedef|;
end_typedef

begin_function_decl
name|void
name|CharData_Init
parameter_list|(
name|CharData
modifier|*
name|storage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CharData_AppendString
parameter_list|(
name|CharData
modifier|*
name|storage
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|CharData_AppendXMLChars
parameter_list|(
name|CharData
modifier|*
name|storage
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CharData_CheckString
parameter_list|(
name|CharData
modifier|*
name|storage
parameter_list|,
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|CharData_CheckXMLChars
parameter_list|(
name|CharData
modifier|*
name|storage
parameter_list|,
specifier|const
name|XML_Char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XML_CHARDATA_H */
end_comment

end_unit

