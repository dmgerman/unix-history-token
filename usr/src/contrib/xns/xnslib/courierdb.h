begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Header: courierdb.h,v 1.1 87/01/05 12:09:41 ed Exp $	*/
end_comment

begin_comment
comment|/* description for the database of courier services, normally  * in the file /etc/Courierservices  */
end_comment

begin_struct
struct|struct
name|courierdbent
block|{
name|char
modifier|*
name|cr_programname
decl_stmt|;
comment|/* the name of the Courier program */
name|unsigned
name|long
name|cr_programnumber
decl_stmt|;
comment|/* official number of program */
name|unsigned
name|short
name|cr_version
decl_stmt|;
comment|/* version number of this server */
name|char
modifier|*
name|cr_description
decl_stmt|;
comment|/* file containing the Courier description */
name|char
modifier|*
name|cr_serverbin
decl_stmt|;
comment|/* file containing the server binary */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|courierdbent
modifier|*
name|getcourierdbent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|courierdbent
modifier|*
name|getcourierservice
parameter_list|()
function_decl|;
end_function_decl

end_unit

