begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  ******************************************************************************  *  * Module: bb_ip.c  *  * Functions:   *	    bb_get_ip_lines()	- Interpret a string to contain IP addresses.  *				- Place the addresses in the IP array and  *				- return the number found and index of first.  *	    bb_check_ip()	- Check if the IP address of the caller is  *				- in the IP list of his specified id name.  *  *  ******************************************************************************  */
end_comment

begin_comment
comment|/*  ******************************************************************************  * Include Files  ******************************************************************************  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"protocol.h"
end_include

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_function_decl
name|char
modifier|*
name|strtok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bb_get_ip
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  get_ip_lines() - Interpret the input 'line' to be a list of internet** **  addresses.  Place them in the internet table and return the starting** **  index of this block as well as the number of addresses in the block.** **									** *************************************************************************/
end_comment

begin_decl_stmt
name|BB_ip
name|bb_ips
index|[
name|BB_MAX_IP
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IP Address array.		*/
end_comment

begin_decl_stmt
name|int
name|bb_ip_count
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of IP's in array.	*/
end_comment

begin_function
name|void
name|bb_get_ip_lines
parameter_list|(
name|line
parameter_list|,
name|p_count
parameter_list|,
name|p_index
parameter_list|)
name|char
modifier|*
name|line
decl_stmt|;
comment|/* The input line of IP address tokens.		*/
name|int
modifier|*
name|p_count
decl_stmt|;
comment|/* Output number of IP addresses in the block.	*/
name|int
modifier|*
name|p_index
decl_stmt|;
comment|/* The starting index of the block of IP addrs.	*/
block|{
name|char
modifier|*
name|ip_addr
decl_stmt|;
comment|/* Points to ip address string.		*/
comment|/*     **  The index of this block of ip addresses is equal to the count.     */
operator|*
name|p_index
operator|=
name|bb_ip_count
expr_stmt|;
operator|*
name|p_count
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|(
name|ip_addr
operator|=
name|strtok
argument_list|(
name|line
argument_list|,
name|BB_IP_SEPARATOR
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ERROR: Null IP address list in data file.\n"
argument_list|)
expr_stmt|;
block|}
do|do
block|{
name|strncpy
argument_list|(
name|bb_ips
index|[
name|bb_ip_count
operator|++
index|]
argument_list|,
name|ip_addr
argument_list|,
name|BB_IP_ADDR_LEN
argument_list|)
expr_stmt|;
operator|(
operator|*
name|p_count
operator|)
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|ip_addr
operator|=
name|strtok
argument_list|(
name|NULL
argument_list|,
name|BB_IP_SEPARATOR
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
do|;
comment|/*     **  Strtok() leaves the \n on the last IP addres, take it off.     */
name|bb_ips
index|[
name|bb_ip_count
operator|-
literal|1
index|]
index|[
name|strlen
argument_list|(
name|bb_ips
index|[
name|bb_ip_count
operator|-
literal|1
index|]
argument_list|)
operator|-
literal|1
index|]
operator|=
name|NUL
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/************************************************************************* **									** **  bb_check_ip() - This function checks to see if the client has an 	** **  entry in the ip list which matches the ip address of this call.	** **									** *************************************************************************/
end_comment

begin_function
name|int
name|bb_check_ip
parameter_list|(
name|client
parameter_list|)
name|BB_id
name|client
decl_stmt|;
comment|/* The clients identifier.		*/
block|{
name|int
name|client_id
decl_stmt|;
comment|/* The index of the client.		*/
name|BB_co_data
name|codata
decl_stmt|;
comment|/* The company data of the client.	*/
name|int
name|i
decl_stmt|;
comment|/* Nice loop variable name.		*/
name|BB_ip
name|ip
decl_stmt|;
comment|/* The ip address of the caller.	*/
comment|/*     **  Get the client's id.     */
if|if
condition|(
operator|(
name|client_id
operator|=
name|bb_get_hash
argument_list|(
name|client
argument_list|)
operator|)
operator|==
name|BB_HASH_ID_NOT_FOUND
condition|)
block|{
return|return
name|BB_BAD_CLIENT
return|;
block|}
comment|/*     **  Get the company data of the client.     */
if|if
condition|(
name|bb_get_codata
argument_list|(
name|client_id
argument_list|,
operator|&
name|codata
argument_list|)
operator|!=
name|BB_SUCCESS
condition|)
block|{
return|return
name|BB_BAD_CLIENT
return|;
block|}
comment|/*     **  Get the ip address of the caller and check it agains the     **  clients list of ip addresses.     */
name|bb_get_ip
argument_list|(
name|ip
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|codata
operator|.
name|ip_idx
init|;
name|i
operator|<
name|codata
operator|.
name|ip_idx
operator|+
name|codata
operator|.
name|ip_cnt
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|strncmp
argument_list|(
name|bb_ips
index|[
name|i
index|]
argument_list|,
name|ip
argument_list|,
name|BB_IP_ADDR_LEN
argument_list|)
operator|==
literal|0
condition|)
block|{
return|return
name|BB_SUCCESS
return|;
block|}
block|}
return|return
name|BB_FAILURE
return|;
block|}
end_function

end_unit

