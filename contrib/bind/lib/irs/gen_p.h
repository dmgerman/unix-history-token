begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996,1999 by Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM DISCLAIMS  * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL INTERNET SOFTWARE  * CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR  * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS  * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS  * SOFTWARE.  */
end_comment

begin_comment
comment|/*  * $Id: gen_p.h,v 1.11 2001/05/29 05:48:39 marka Exp $  */
end_comment

begin_comment
comment|/* Notes:  *	We hope to create a complete set of thread-safe entry points someday,  *	which will mean a set of getXbyY() functions that take as an argument  *	a pointer to the map class, which will have a pointer to the private  *	data, which will be used preferentially to the static variables that  *	are necessary to support the "classic" interface.  This "classic"  *	interface will then be reimplemented as stubs on top of the thread  *	safe modules, and will keep the map class pointers as their only  *	static data.  HOWEVER, we are not there yet.  So while we will call  *	the just-barely-converted map class methods with map class pointers,  *	right now they probably all still use statics.  We're not fooling  *	anybody, and we're not trying to (yet).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEN_P_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|_GEN_P_H_INCLUDED
end_define

begin_comment
comment|/*  * These are the access methods.  */
end_comment

begin_enum
enum|enum
name|irs_acc_id
block|{
name|irs_lcl
block|,
comment|/* Local. */
name|irs_dns
block|,
comment|/* DNS or Hesiod. */
name|irs_nis
block|,
comment|/* Sun NIS ("YP"). */
name|irs_irp
block|,
comment|/* IR protocol.  */
name|irs_nacc
block|}
enum|;
end_enum

begin_comment
comment|/*  * These are the map types.  */
end_comment

begin_enum
enum|enum
name|irs_map_id
block|{
name|irs_gr
block|,
comment|/* "group" */
name|irs_pw
block|,
comment|/* "passwd" */
name|irs_sv
block|,
comment|/* "services" */
name|irs_pr
block|,
comment|/* "protocols" */
name|irs_ho
block|,
comment|/* "hosts" */
name|irs_nw
block|,
comment|/* "networks" */
name|irs_ng
block|,
comment|/* "netgroup" */
name|irs_nmap
block|}
enum|;
end_enum

begin_comment
comment|/*  * This is an accessor instance.  */
end_comment

begin_struct
struct|struct
name|irs_inst
block|{
name|struct
name|irs_acc
modifier|*
name|acc
decl_stmt|;
name|struct
name|irs_gr
modifier|*
name|gr
decl_stmt|;
name|struct
name|irs_pw
modifier|*
name|pw
decl_stmt|;
name|struct
name|irs_sv
modifier|*
name|sv
decl_stmt|;
name|struct
name|irs_pr
modifier|*
name|pr
decl_stmt|;
name|struct
name|irs_ho
modifier|*
name|ho
decl_stmt|;
name|struct
name|irs_nw
modifier|*
name|nw
decl_stmt|;
name|struct
name|irs_ng
modifier|*
name|ng
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * This is a search rule for some map type.  */
end_comment

begin_struct
struct|struct
name|irs_rule
block|{
name|struct
name|irs_rule
modifier|*
name|next
decl_stmt|;
name|struct
name|irs_inst
modifier|*
name|inst
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IRS_MERGE
value|0x0001
end_define

begin_comment
comment|/* Don't stop if acc. has data? */
end_comment

begin_define
define|#
directive|define
name|IRS_CONTINUE
value|0x0002
end_define

begin_comment
comment|/* Don't stop if acc. has no data? */
end_comment

begin_comment
comment|/*  * This is the private data for a search access class.  */
end_comment

begin_struct
struct|struct
name|gen_p
block|{
name|char
modifier|*
name|options
decl_stmt|;
name|struct
name|irs_rule
modifier|*
name|map_rules
index|[
operator|(
name|int
operator|)
name|irs_nmap
index|]
decl_stmt|;
name|struct
name|irs_inst
name|accessors
index|[
operator|(
name|int
operator|)
name|irs_nacc
index|]
decl_stmt|;
name|struct
name|__res_state
modifier|*
name|res
decl_stmt|;
name|void
argument_list|(
argument|*free_res
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Externs.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|irs_acc
modifier|*
name|irs_gen_acc
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
name|conf_file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_gr
modifier|*
name|irs_gen_gr
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_pw
modifier|*
name|irs_gen_pw
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_sv
modifier|*
name|irs_gen_sv
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_pr
modifier|*
name|irs_gen_pr
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_ho
modifier|*
name|irs_gen_ho
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_nw
modifier|*
name|irs_gen_nw
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|irs_ng
modifier|*
name|irs_gen_ng
name|__P
argument_list|(
operator|(
expr|struct
name|irs_acc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_IRS_P_H_INCLUDED*/
end_comment

end_unit

