begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Ticket lifetime.  This defines the table used to lookup lifetime  * for the fixed part of rande of the one byte lifetime field.  Values  * less than 0x80 are intrpreted as the number of 5 minute intervals.  * Values from 0x80 to 0xBF should be looked up in this table.  The  * value of 0x80 is the same using both methods: 10 and two-thirds  * hours .  The lifetime of 0xBF is 30 days.  The intervening values  * of have a fixed ratio of roughly 1.06914.  The value 0xFF is  * defined to mean a ticket has no expiration time.  This should be  * used advisedly since individual servers may impose defacto  * upperbounds on ticket lifetimes.  */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: lifetime.c,v 1.9 1997/05/02 14:29:18 assar Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* If you want to disable this feature */
end_comment

begin_decl_stmt
name|int
name|krb_no_long_lifetimes
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TKTLIFENUMFIXED
value|64
end_define

begin_define
define|#
directive|define
name|TKTLIFEMINFIXED
value|0x80
end_define

begin_define
define|#
directive|define
name|TKTLIFEMAXFIXED
value|0xBF
end_define

begin_define
define|#
directive|define
name|TKTLIFENOEXPIRE
value|0xFF
end_define

begin_define
define|#
directive|define
name|MAXTKTLIFETIME
value|(30*24*3600)
end_define

begin_comment
comment|/* 30 days */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NEVERDATE
end_ifndef

begin_define
define|#
directive|define
name|NEVERDATE
value|((unsigned long)0x7fffffffL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|int
name|tkt_lifetimes
index|[
name|TKTLIFENUMFIXED
index|]
init|=
block|{
literal|38400
block|,
comment|/* 10.67 hours, 0.44 days */
literal|41055
block|,
comment|/* 11.40 hours, 0.48 days */
literal|43894
block|,
comment|/* 12.19 hours, 0.51 days */
literal|46929
block|,
comment|/* 13.04 hours, 0.54 days */
literal|50174
block|,
comment|/* 13.94 hours, 0.58 days */
literal|53643
block|,
comment|/* 14.90 hours, 0.62 days */
literal|57352
block|,
comment|/* 15.93 hours, 0.66 days */
literal|61318
block|,
comment|/* 17.03 hours, 0.71 days */
literal|65558
block|,
comment|/* 18.21 hours, 0.76 days */
literal|70091
block|,
comment|/* 19.47 hours, 0.81 days */
literal|74937
block|,
comment|/* 20.82 hours, 0.87 days */
literal|80119
block|,
comment|/* 22.26 hours, 0.93 days */
literal|85658
block|,
comment|/* 23.79 hours, 0.99 days */
literal|91581
block|,
comment|/* 25.44 hours, 1.06 days */
literal|97914
block|,
comment|/* 27.20 hours, 1.13 days */
literal|104684
block|,
comment|/* 29.08 hours, 1.21 days */
literal|111922
block|,
comment|/* 31.09 hours, 1.30 days */
literal|119661
block|,
comment|/* 33.24 hours, 1.38 days */
literal|127935
block|,
comment|/* 35.54 hours, 1.48 days */
literal|136781
block|,
comment|/* 37.99 hours, 1.58 days */
literal|146239
block|,
comment|/* 40.62 hours, 1.69 days */
literal|156350
block|,
comment|/* 43.43 hours, 1.81 days */
literal|167161
block|,
comment|/* 46.43 hours, 1.93 days */
literal|178720
block|,
comment|/* 49.64 hours, 2.07 days */
literal|191077
block|,
comment|/* 53.08 hours, 2.21 days */
literal|204289
block|,
comment|/* 56.75 hours, 2.36 days */
literal|218415
block|,
comment|/* 60.67 hours, 2.53 days */
literal|233517
block|,
comment|/* 64.87 hours, 2.70 days */
literal|249664
block|,
comment|/* 69.35 hours, 2.89 days */
literal|266926
block|,
comment|/* 74.15 hours, 3.09 days */
literal|285383
block|,
comment|/* 79.27 hours, 3.30 days */
literal|305116
block|,
comment|/* 84.75 hours, 3.53 days */
literal|326213
block|,
comment|/* 90.61 hours, 3.78 days */
literal|348769
block|,
comment|/* 96.88 hours, 4.04 days */
literal|372885
block|,
comment|/* 103.58 hours, 4.32 days */
literal|398668
block|,
comment|/* 110.74 hours, 4.61 days */
literal|426234
block|,
comment|/* 118.40 hours, 4.93 days */
literal|455705
block|,
comment|/* 126.58 hours, 5.27 days */
literal|487215
block|,
comment|/* 135.34 hours, 5.64 days */
literal|520904
block|,
comment|/* 144.70 hours, 6.03 days */
literal|556921
block|,
comment|/* 154.70 hours, 6.45 days */
literal|595430
block|,
comment|/* 165.40 hours, 6.89 days */
literal|636601
block|,
comment|/* 176.83 hours, 7.37 days */
literal|680618
block|,
comment|/* 189.06 hours, 7.88 days */
literal|727680
block|,
comment|/* 202.13 hours, 8.42 days */
literal|777995
block|,
comment|/* 216.11 hours, 9.00 days */
literal|831789
block|,
comment|/* 231.05 hours, 9.63 days */
literal|889303
block|,
comment|/* 247.03 hours, 10.29 days */
literal|950794
block|,
comment|/* 264.11 hours, 11.00 days */
literal|1016537
block|,
comment|/* 282.37 hours, 11.77 days */
literal|1086825
block|,
comment|/* 301.90 hours, 12.58 days */
literal|1161973
block|,
comment|/* 322.77 hours, 13.45 days */
literal|1242318
block|,
comment|/* 345.09 hours, 14.38 days */
literal|1328218
block|,
comment|/* 368.95 hours, 15.37 days */
literal|1420057
block|,
comment|/* 394.46 hours, 16.44 days */
literal|1518247
block|,
comment|/* 421.74 hours, 17.57 days */
literal|1623226
block|,
comment|/* 450.90 hours, 18.79 days */
literal|1735464
block|,
comment|/* 482.07 hours, 20.09 days */
literal|1855462
block|,
comment|/* 515.41 hours, 21.48 days */
literal|1983758
block|,
comment|/* 551.04 hours, 22.96 days */
literal|2120925
block|,
comment|/* 589.15 hours, 24.55 days */
literal|2267576
block|,
comment|/* 629.88 hours, 26.25 days */
literal|2424367
block|,
comment|/* 673.44 hours, 28.06 days */
literal|2592000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 720.00 hours, 30.00 days */
end_comment

begin_comment
comment|/*  * krb_life_to_time - takes a start time and a Kerberos standard  * lifetime char and returns the corresponding end time.  There are  * four simple cases to be handled.  The first is a life of 0xff,  * meaning no expiration, and results in an end time of 0xffffffff.  * The second is when life is less than the values covered by the  * table.  In this case, the end time is the start time plus the  * number of 5 minute intervals specified by life.  The third case  * returns start plus the MAXTKTLIFETIME if life is greater than  * TKTLIFEMAXFIXED.  The last case, uses the life value (minus  * TKTLIFEMINFIXED) as an index into the table to extract the lifetime  * in seconds, which is added to start to produce the end time.  */
end_comment

begin_function
name|u_int32_t
name|krb_life_to_time
parameter_list|(
name|u_int32_t
name|start
parameter_list|,
name|int
name|life_
parameter_list|)
block|{
name|unsigned
name|char
name|life
init|=
operator|(
name|unsigned
name|char
operator|)
name|life_
decl_stmt|;
if|if
condition|(
name|krb_no_long_lifetimes
condition|)
return|return
name|start
operator|+
name|life
operator|*
literal|5
operator|*
literal|60
return|;
if|if
condition|(
name|life
operator|==
name|TKTLIFENOEXPIRE
condition|)
return|return
name|NEVERDATE
return|;
if|if
condition|(
name|life
operator|<
name|TKTLIFEMINFIXED
condition|)
return|return
name|start
operator|+
name|life
operator|*
literal|5
operator|*
literal|60
return|;
if|if
condition|(
name|life
operator|>
name|TKTLIFEMAXFIXED
condition|)
return|return
name|start
operator|+
name|MAXTKTLIFETIME
return|;
return|return
name|start
operator|+
name|tkt_lifetimes
index|[
name|life
operator|-
name|TKTLIFEMINFIXED
index|]
return|;
block|}
end_function

begin_comment
comment|/*  * krb_time_to_life - takes start and end times for the ticket and  * returns a Kerberos standard lifetime char, possibily using the  * tkt_lifetimes table for lifetimes above 127*5 minutes.  First, the  * special case of (end == NEVERDATE) is handled to mean no  * expiration.  Then negative lifetimes and those greater than the  * maximum ticket lifetime are rejected.  Then lifetimes less than the  * first table entry are handled by rounding the requested lifetime  * *up* to the next 5 minute interval.  The final step is to search  * the table for the smallest entry *greater than or equal* to the  * requested entry.  */
end_comment

begin_function
name|int
name|krb_time_to_life
parameter_list|(
name|u_int32_t
name|start
parameter_list|,
name|u_int32_t
name|end
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|long
name|lifetime
init|=
name|end
operator|-
name|start
decl_stmt|;
if|if
condition|(
name|krb_no_long_lifetimes
condition|)
return|return
operator|(
name|lifetime
operator|+
literal|5
operator|*
literal|60
operator|-
literal|1
operator|)
operator|/
operator|(
literal|5
operator|*
literal|60
operator|)
return|;
if|if
condition|(
name|end
operator|>=
name|NEVERDATE
condition|)
return|return
name|TKTLIFENOEXPIRE
return|;
if|if
condition|(
name|lifetime
operator|>
name|MAXTKTLIFETIME
operator|||
name|lifetime
operator|<=
literal|0
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|lifetime
operator|<
name|tkt_lifetimes
index|[
literal|0
index|]
condition|)
return|return
operator|(
name|lifetime
operator|+
literal|5
operator|*
literal|60
operator|-
literal|1
operator|)
operator|/
operator|(
literal|5
operator|*
literal|60
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|TKTLIFENUMFIXED
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|lifetime
operator|<=
name|tkt_lifetimes
index|[
name|i
index|]
condition|)
block|{
return|return
name|i
operator|+
name|TKTLIFEMINFIXED
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|krb_life_to_atime
parameter_list|(
name|int
name|life
parameter_list|)
block|{
specifier|static
name|char
name|atime
index|[
literal|11
operator|+
literal|1
operator|+
literal|2
operator|+
literal|1
operator|+
literal|2
operator|+
literal|1
operator|+
literal|2
operator|+
literal|1
index|]
decl_stmt|;
name|unsigned
name|long
name|when
decl_stmt|;
name|int
name|secs
decl_stmt|,
name|mins
decl_stmt|,
name|hours
decl_stmt|;
if|if
condition|(
name|life
operator|==
name|TKTLIFENOEXPIRE
operator|&&
operator|!
name|krb_no_long_lifetimes
condition|)
return|return
operator|(
literal|"Forever"
operator|)
return|;
name|when
operator|=
name|krb_life_to_time
argument_list|(
literal|0
argument_list|,
name|life
argument_list|)
expr_stmt|;
name|secs
operator|=
name|when
operator|%
literal|60
expr_stmt|;
name|when
operator|/=
literal|60
expr_stmt|;
name|mins
operator|=
name|when
operator|%
literal|60
expr_stmt|;
name|when
operator|/=
literal|60
expr_stmt|;
name|hours
operator|=
name|when
operator|%
literal|24
expr_stmt|;
name|when
operator|/=
literal|24
expr_stmt|;
name|snprintf
argument_list|(
name|atime
argument_list|,
sizeof|sizeof
argument_list|(
name|atime
argument_list|)
argument_list|,
literal|"%d+%02d:%02d:%02d"
argument_list|,
operator|(
name|int
operator|)
name|when
argument_list|,
name|hours
argument_list|,
name|mins
argument_list|,
name|secs
argument_list|)
expr_stmt|;
return|return
operator|(
name|atime
operator|)
return|;
block|}
end_function

begin_function
name|int
name|krb_atime_to_life
parameter_list|(
name|char
modifier|*
name|atime
parameter_list|)
block|{
name|unsigned
name|long
name|when
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|int
name|colon
init|=
literal|0
decl_stmt|,
name|plus
init|=
literal|0
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|atime
argument_list|,
literal|"forever"
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|TKTLIFENOEXPIRE
operator|)
return|;
for|for
control|(
name|cp
operator|=
name|atime
init|;
operator|*
name|cp
condition|;
name|cp
operator|++
control|)
block|{
switch|switch
condition|(
operator|*
name|cp
condition|)
block|{
case|case
literal|'0'
case|:
case|case
literal|'1'
case|:
case|case
literal|'2'
case|:
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
case|case
literal|'5'
case|:
case|case
literal|'6'
case|:
case|case
literal|'7'
case|:
case|case
literal|'8'
case|:
case|case
literal|'9'
case|:
name|n
operator|=
name|n
operator|*
literal|10
operator|+
operator|*
name|cp
operator|-
literal|'0'
expr_stmt|;
break|break;
case|case
literal|'+'
case|:
name|plus
operator|++
expr_stmt|;
name|when
operator|+=
name|n
expr_stmt|;
name|when
operator|*=
literal|24
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|':'
case|:
name|colon
operator|++
expr_stmt|;
name|when
operator|+=
name|n
expr_stmt|;
name|when
operator|*=
literal|60
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
name|when
operator|+=
name|n
expr_stmt|;
if|if
condition|(
name|plus
operator|==
literal|0
operator|&&
name|colon
operator|==
literal|0
condition|)
return|return
operator|(
operator|(
name|unsigned
name|char
operator|)
name|when
operator|)
return|;
while|while
condition|(
name|colon
operator|<
literal|2
condition|)
block|{
name|when
operator|*=
literal|60
expr_stmt|;
name|colon
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|krb_time_to_life
argument_list|(
literal|0
argument_list|,
name|when
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

