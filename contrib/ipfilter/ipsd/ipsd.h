begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * (C)opyright 1995-1998 Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  *   The author of this software makes no garuntee about the  * performance of this package or its suitability to fulfill any purpose.  *  * @(#)ipsd.h	1.3 12/3/95  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|time_t
name|sh_date
decl_stmt|;
name|struct
name|in_addr
name|sh_ip
decl_stmt|;
block|}
name|sdhit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|sd_sz
decl_stmt|;
name|u_int
name|sd_cnt
decl_stmt|;
name|u_short
name|sd_port
decl_stmt|;
name|sdhit_t
modifier|*
name|sd_hit
decl_stmt|;
block|}
name|ipsd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|in_addr
name|ss_ip
decl_stmt|;
name|int
name|ss_hits
decl_stmt|;
name|u_long
name|ss_ports
decl_stmt|;
block|}
name|ipss_t
typedef|;
end_typedef

end_unit

