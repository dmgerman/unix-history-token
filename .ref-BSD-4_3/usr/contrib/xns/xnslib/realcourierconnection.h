begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: realcourierconnection.h,v 2.0 85/11/21 07:22:17 jqj Exp $ */
end_comment

begin_comment
comment|/*  $Log:	realcourierconnection.h,v $  * Revision 2.0  85/11/21  07:22:17  jqj  * 4.3BSD standard release  *   * Revision 1.3  85/03/11  16:37:04  jqj  * *** empty log message ***  *   * Revision 1.3  85/03/11  16:37:04  jqj  * Public alpha-test version, released 11 March 1985  *   * Revision 1.2  85/01/27  07:37:24  jqj  * finished but undebugged version  *   */
end_comment

begin_comment
comment|/*  * entries in the database of active Courier connections  * This file replaces the definition of ``#define CourierConnection int''  * in courier.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CourierConnectionHeader
end_ifndef

begin_define
define|#
directive|define
name|CourierConnectionHeader
end_define

begin_enum
enum|enum
name|connectionstate
block|{
name|closed
block|,
comment|/* no SPP connection */
name|wantversion
block|,
comment|/* need to receive Courier version */
name|inprogress
block|,
comment|/* got version, but no RETURN yet */
name|calldone
comment|/* transaction completed.  Waiting for call */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|bdtconnectionstate
block|{
name|wantdata
block|,
comment|/* call, but no reply on BDT connection */
name|established
block|,
comment|/* in middle of BDT transfer */
name|bdteomseen
comment|/* BDT data done */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd
decl_stmt|;
name|int
name|abortseen
decl_stmt|;
name|enum
name|connectionstate
name|state
decl_stmt|;
name|enum
name|bdtconnectionstate
name|bdtstate
decl_stmt|;
name|struct
name|sockaddr_ns
name|host
decl_stmt|;
name|struct
name|sphdr
name|sphdrOpts
decl_stmt|;
block|}
name|CourierConnection
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|CourierConnection
modifier|*
name|CourierOpen
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

