begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Efficient ENI adapter support  * -----------------------------  *  * Module supports PCI interface to ENI adapter  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/socketvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/queue.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_cm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_stack.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_pcb.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni_stats.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni.h>
end_include

begin_include
include|#
directive|include
file|<dev/hea/eni_var.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Typedef local functions  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static const char	*eni_pci_probe(pcici_t, pcidi_t); static void	eni_pci_attach(pcici_t, int);
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|int
name|eni_get_ack
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|eni_get_sebyte
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eni_read_seeprom
parameter_list|(
name|Eni_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_if
if|#
directive|if
name|BSD
operator|<
literal|199506
end_if

begin_else
unit|static int	eni_pci_shutdown(struct kern_devconf *, int);
else|#
directive|else
end_else

begin_endif
unit|static void	eni_pci_shutdown(void *, int);
endif|#
directive|endif
end_endif

begin_endif
unit|static void	eni_pci_reset(Eni_unit *);
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Used by kernel to return number of claimed devices  */
end_comment

begin_if
unit|static u_long eni_nunits;  static struct pci_device eni_pci_device = { 	ENI_DEV_NAME, 	eni_pci_probe, 	eni_pci_attach,&eni_nunits,
if|#
directive|if
name|BSD
operator|<
literal|199506
end_if

begin_else
unit|eni_pci_shutdown
else|#
directive|else
end_else

begin_endif
unit|NULL
endif|#
directive|endif
end_endif

begin_comment
unit|};  COMPAT_PCI_DRIVER (eni_pci, eni_pci_device);
comment|/*  * Called by kernel with PCI device_id which was read from the PCI  * register set. If the identified vendor is Efficient, see if we  * recognize the particular device. If so, return an identifying string,  * if not, return null.  *  * Arguments:  *	config_id	PCI config token  *	device_id	contents of PCI device ID register  *  * Returns:  *	string		Identifying string if we will handle this device  *	NULL		unrecognized vendor/device  *  */
end_comment

begin_comment
unit|static const char * eni_pci_probe ( pcici_t config_id, pcidi_t device_id ) {  	if ( (device_id& 0xFFFF) == EFF_VENDOR_ID ) { 		switch ( (device_id>> 16) ) { 			case EFF_DEV_ID: 				return ( "Efficient ENI ATM Adapter" );
comment|/* NOTREACHED */
end_comment

begin_endif
unit|break; 		} 	}  	return ( NULL ); }
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The ENI-155p adapter uses an ATMEL AT24C01 serial EEPROM to store  * configuration information. The SEEPROM is accessed via two wires,  * CLOCK and DATA, which are accessible via the PCI configuration  * registers. The following macros manipulate the lines to access the  * SEEPROM. See http://www.atmel.com/atmel/products/prod162.htm for  * a description of the AT24C01 part. Value to be read/written is  * part of the per unit structure.  */
end_comment

begin_comment
comment|/*  * Write bits to SEEPROM  */
end_comment

begin_define
define|#
directive|define
name|WRITE_SEEPROM
parameter_list|()
value|(						\     {									\ 	(void) pci_write_config(eup->eu_pcitag, SEEPROM,		\ 		eup->eu_sevar, 4);					\ 	DELAY(SEPROM_DELAY);						\     }									\ )
end_define

begin_comment
comment|/*  * Stobe first the DATA, then the CLK lines high  */
end_comment

begin_define
define|#
directive|define
name|STROBE_HIGH
parameter_list|()
value|(						\     {									\ 	eup->eu_sevar |= SEPROM_DATA; WRITE_SEEPROM();			\ 	eup->eu_sevar |= SEPROM_CLK;  WRITE_SEEPROM();			\     }									\ )
end_define

begin_comment
comment|/*  * Strobe first the CLK, then the DATA lines high  */
end_comment

begin_define
define|#
directive|define
name|INV_STROBE_HIGH
parameter_list|()
value|(					\     {									\ 	eup->eu_sevar |= SEPROM_CLK;  WRITE_SEEPROM();			\ 	eup->eu_sevar |= SEPROM_DATA; WRITE_SEEPROM();			\     }									\ )
end_define

begin_comment
comment|/*  * Strobe first the CLK, then the DATA lines low - companion to  * STROBE_HIGH()  */
end_comment

begin_define
define|#
directive|define
name|STROBE_LOW
parameter_list|()
value|(						\     {									\ 	eup->eu_sevar&= ~SEPROM_CLK;  WRITE_SEEPROM();			\ 	eup->eu_sevar&= ~SEPROM_DATA; WRITE_SEEPROM();			\     }									\ )
end_define

begin_comment
comment|/*  * Strobe first the DATA, then the CLK lines low - companion to  * INV_STROBE_HIGH()  */
end_comment

begin_define
define|#
directive|define
name|INV_STROBE_LOW
parameter_list|()
value|(					\     {									\ 	eup->eu_sevar&= ~SEPROM_DATA; WRITE_SEEPROM();			\ 	eup->eu_sevar&= ~SEPROM_CLK;  WRITE_SEEPROM();			\     }									\ )
end_define

begin_comment
comment|/*  * Strobe the CLK line high, then low  */
end_comment

begin_define
define|#
directive|define
name|STROBE_CLK
parameter_list|()
value|(						\     {									\ 	eup->eu_sevar |= SEPROM_CLK;   WRITE_SEEPROM();			\ 	eup->eu_sevar&= ~SEPROM_CLK;  WRITE_SEEPROM();			\     }									\ )
end_define

begin_comment
comment|/*  * Look for a positive ACK from the SEEPROM. Cycle begins by asserting  * the DATA line, then the CLK line. The DATA line is then read to  * retrieve the ACK status, and then the cycle is finished by deasserting  * the CLK line, and asserting the DATA line.  *  * Arguments:  *	eup		pointer to per unit structure  *  * Returns:  *	0/1		value of ACK  *  */
end_comment

begin_function
specifier|static
name|int
name|eni_get_ack
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|int
name|ack
decl_stmt|;
name|STROBE_HIGH
argument_list|()
expr_stmt|;
comment|/* 	 * Read DATA line from SEPROM 	 */
name|eup
operator|->
name|eu_sevar
operator|=
name|pci_read_config
argument_list|(
name|eup
operator|->
name|eu_pcitag
argument_list|,
name|SEEPROM
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|SEPROM_DELAY
argument_list|)
expr_stmt|;
name|ack
operator|=
name|eup
operator|->
name|eu_sevar
operator|&
name|SEPROM_DATA
expr_stmt|;
name|eup
operator|->
name|eu_sevar
operator|&=
operator|~
name|SEPROM_CLK
expr_stmt|;
name|WRITE_SEEPROM
argument_list|()
expr_stmt|;
name|eup
operator|->
name|eu_sevar
operator||=
name|SEPROM_DATA
expr_stmt|;
name|WRITE_SEEPROM
argument_list|()
expr_stmt|;
return|return
operator|(
name|ack
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Read a byte from the SEEPROM. Data is read as 8 bits. There are two types  * of read operations. The first is a single byte read, the second is  * multiple sequential bytes read. Both cycles begin with a 'START' operation,  * followed by a memory address word. Following the memory address, the  * SEEPROM will send a data byte, followed by an ACK. If the host responds  * with a 'STOP' operation, then a single byte cycle is performed. If the  * host responds with an 'ACK', then the memory address is incremented, and  * the next sequential memory byte is serialized.  *  * Arguments:  *	eup		pointer to per unit structure  *  * Returns:  *	val		value of byte read from SEEPROM  *  */
end_comment

begin_function
specifier|static
name|int
name|eni_get_sebyte
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|int
name|data
decl_stmt|;
name|int
name|rval
decl_stmt|;
comment|/* Initial value */
name|rval
operator|=
literal|0
expr_stmt|;
comment|/* Read 8 bits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
condition|;
name|i
operator|++
control|)
block|{
comment|/* Shift bits to left so the next bit goes to position 0 */
name|rval
operator|<<=
literal|1
expr_stmt|;
comment|/* Indicate we're ready to read bit */
name|STROBE_HIGH
argument_list|()
expr_stmt|;
comment|/* 		 * Read DATA line from SEPROM 		 */
name|data
operator|=
name|pci_read_config
argument_list|(
name|eup
operator|->
name|eu_pcitag
argument_list|,
name|SEEPROM
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|DELAY
argument_list|(
name|SEPROM_DELAY
argument_list|)
expr_stmt|;
comment|/* (Possibly) mask bit into accumulating value */
if|if
condition|(
name|data
operator|&
name|SEPROM_DATA
condition|)
name|rval
operator||=
literal|1
expr_stmt|;
comment|/* If DATA bit '1' */
comment|/* Indicate we're done reading this bit */
name|STROBE_LOW
argument_list|()
expr_stmt|;
block|}
comment|/* Return acquired byte */
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The AT24C01 is a 1024 bit part organized as 128 words by 8 bits.  * We will read the entire contents into the per unit structure. Later,  * we'll retrieve the MAC address and serial number from the data read.  *  * Arguments:  *	eup		pointer to per unit structure  *  * Returns:  *	none  *  */
end_comment

begin_function
name|void
name|eni_read_seeprom
parameter_list|(
name|eup
parameter_list|)
name|Eni_unit
modifier|*
name|eup
decl_stmt|;
block|{
name|int
name|addr
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
comment|/* 	 * Set initial state 	 */
name|eup
operator|->
name|eu_sevar
operator|=
name|SEPROM_DATA
operator||
name|SEPROM_CLK
expr_stmt|;
name|WRITE_SEEPROM
argument_list|()
expr_stmt|;
comment|/* Loop for all bytes */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SEPROM_SIZE
condition|;
name|i
operator|++
control|)
block|{
comment|/* Send START operation */
name|STROBE_HIGH
argument_list|()
expr_stmt|;
name|INV_STROBE_LOW
argument_list|()
expr_stmt|;
comment|/* 		 * Send address. Addresses are sent as 7 bits plus 		 * last bit high. 		 */
name|addr
operator|=
operator|(
operator|(
name|i
operator|)
operator|<<
literal|1
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* 		 * Start with high order bit first working toward low 		 * order bit. 		 */
for|for
control|(
name|j
operator|=
literal|7
init|;
name|j
operator|>=
literal|0
condition|;
name|j
operator|--
control|)
block|{
comment|/* Set current bit value */
name|eup
operator|->
name|eu_sevar
operator|=
operator|(
name|addr
operator|>>
name|j
operator|)
operator|&
literal|1
condition|?
name|eup
operator|->
name|eu_sevar
operator||
name|SEPROM_DATA
else|:
name|eup
operator|->
name|eu_sevar
operator|&
operator|~
name|SEPROM_DATA
expr_stmt|;
name|WRITE_SEEPROM
argument_list|()
expr_stmt|;
comment|/* Indicate we've sent it */
name|STROBE_CLK
argument_list|()
expr_stmt|;
block|}
comment|/* 		 * We expect a zero ACK after sending the address 		 */
if|if
condition|(
operator|!
name|eni_get_ack
argument_list|(
name|eup
argument_list|)
condition|)
block|{
comment|/* Address okay - read data byte */
name|eup
operator|->
name|eu_seeprom
index|[
name|i
index|]
operator|=
name|eni_get_sebyte
argument_list|(
name|eup
argument_list|)
expr_stmt|;
comment|/* Grab but ignore the ACK op */
operator|(
name|void
operator|)
name|eni_get_ack
argument_list|(
name|eup
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Address ACK was bad - can't retrieve data byte */
name|eup
operator|->
name|eu_seeprom
index|[
name|i
index|]
operator|=
literal|0xff
expr_stmt|;
block|}
block|}
return|return;
block|}
end_function

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * The kernel has found a device which we are willing to support.  * We are now being called to do any necessary work to make the  * device initially usable. In our case, this means allocating  * structure memory, configuring registers, mapping device  * memory, setting pointers, registering with the core services,  * and doing the initial PDU processing configuration.  *  * Arguments:  *	config_id		PCI device token  *	unit			instance of the unit  *  * Returns:  *	none		  *  */
end_comment

begin_comment
unit|static void eni_pci_attach ( pcici_t config_id, int unit ) { 	vm_offset_t	va; 	vm_offset_t	pa; 	Eni_unit	*eup; 	long		val;
comment|/* 	 * Just checking... 	 */
end_comment

begin_comment
unit|if ( unit>= ENI_MAX_UNITS ) { 		log ( LOG_ERR, "%s%d: too many devices\n", 			ENI_DEV_NAME, unit ); 		return; 	}
comment|/* 	 * Make sure this isn't a duplicate unit 	 */
end_comment

begin_comment
unit|if ( eni_units[unit] != NULL ) 		return;
comment|/* 	 * Allocate a new unit structure 	 */
end_comment

begin_comment
unit|eup = (Eni_unit *) atm_dev_alloc ( sizeof(Eni_unit), sizeof(int), 0 ); 	if ( eup == NULL ) 		return;
comment|/* 	 * Start initializing it 	 */
end_comment

begin_comment
unit|eup->eu_unit = unit; 	eup->eu_mtu = ENI_IFF_MTU; 	eup->eu_pcitag = config_id; 	eup->eu_ioctl = eni_atm_ioctl; 	eup->eu_instvcc = eni_instvcc; 	eup->eu_openvcc = eni_openvcc; 	eup->eu_closevcc = eni_closevcc; 	eup->eu_output = eni_output; 	eup->eu_vcc_zone = eni_vcc_zone; 	eup->eu_nif_zone = eni_nif_zone;
comment|/* 	 * Enable Memory Mapping / Bus Mastering  	 */
end_comment

begin_comment
unit|val = pci_conf_read(config_id, PCI_COMMAND_STATUS_REG); 	val |= (PCIM_CMD_MEMEN | PCIM_CMD_BUSMASTEREN); 	pci_conf_write(config_id, PCI_COMMAND_STATUS_REG, val);
comment|/* 	 * Map in adapter RAM 	 */
end_comment

begin_comment
unit|val = pci_conf_read(config_id, PCI_COMMAND_STATUS_REG); 	if ((val& PCIM_CMD_MEMEN) == 0) { 		log(LOG_ERR, "%s%d: memory mapping not enabled\n",  			ENI_DEV_NAME, unit); 		goto failed; 	} 	if ( ( pci_map_mem ( config_id, PCI_MAP_REG_START,&va,&pa ) ) == 0 ) 	{ 		log(LOG_ERR, "%s%d: unable to map memory\n",  			ENI_DEV_NAME, unit); 		goto failed; 	}
comment|/* 	 * Map okay - retain address assigned 	 */
end_comment

begin_comment
unit|eup->eu_base = (Eni_mem)va; 	eup->eu_ram = (Eni_mem)(eup->eu_base + RAM_OFFSET);
comment|/* 	 * Map memory structures into adapter space 	 */
end_comment

begin_comment
unit|eup->eu_suni = (Eni_mem)(eup->eu_base + SUNI_OFFSET); 	eup->eu_midway = (Eni_mem)(eup->eu_base + MIDWAY_OFFSET); 	eup->eu_vcitbl = (VCI_Table *)(eup->eu_base + VCITBL_OFFSET); 	eup->eu_rxdma = (Eni_mem)(eup->eu_base + RXQUEUE_OFFSET); 	eup->eu_txdma = (Eni_mem)(eup->eu_base + TXQUEUE_OFFSET); 	eup->eu_svclist = (Eni_mem)(eup->eu_base + SVCLIST_OFFSET); 	eup->eu_servread = 0;
comment|/* 	 * Reset the midway chip 	 */
end_comment

begin_comment
unit|eup->eu_midway[MIDWAY_ID] = MIDWAY_RESET;
comment|/* 	 * Size and test adapter memory. Initialize our adapter memory 	 * allocater. 	 */
end_comment

begin_comment
unit|if ( eni_init_memory ( eup )< 0 ) {
comment|/* 		 * Adapter memory test failed. Clean up and 		 * return. 		 */
end_comment

begin_comment
unit|log(LOG_ERR, "%s%d: memory test failed\n",  			ENI_DEV_NAME, unit); 		goto failed; 	}
comment|/* 	 * Read the contents of the SEEPROM 	 */
end_comment

begin_comment
unit|eni_read_seeprom ( eup );
comment|/* 	 * Copy MAC address to PIF and config structures 	 */
end_comment

begin_comment
unit|bcopy ( (caddr_t)&eup->eu_seeprom[SEPROM_MAC_OFF], 	    (caddr_t)&eup->eu_pif.pif_macaddr, sizeof(struct mac_addr) ); 	eup->eu_config.ac_macaddr = eup->eu_pif.pif_macaddr;
comment|/* 	 * Copy serial number into config space 	 */
end_comment

begin_comment
unit|eup->eu_config.ac_serial = 		ntohl(*(u_long *)&eup->eu_seeprom[SEPROM_SN_OFF]);
comment|/* 	 * Convert Endianess on DMA 	 */
end_comment

begin_comment
unit|val = pci_conf_read ( config_id, PCI_CONTROL_REG ); 	val |= ENDIAN_SWAP_DMA; 	pci_conf_write ( config_id, PCI_CONTROL_REG, val );
comment|/* 	 * Map interrupt in 	 */
end_comment

begin_comment
unit|if ( !pci_map_int ( config_id, eni_intr, (void *)eup,&net_imask ) ) 	{ 		log(LOG_ERR, "%s%d: unable to map interrupt\n",  			ENI_DEV_NAME, unit); 		goto failed; 	}
comment|/* 	 * Setup some of the adapter configuration 	 */
end_comment

begin_comment
comment|/* 	 * Get MIDWAY ID 	 */
end_comment

begin_comment
unit|val = eup->eu_midway[MIDWAY_ID]; 	eup->eu_config.ac_vendor = VENDOR_ENI; 	eup->eu_config.ac_vendapi = VENDAPI_ENI_1; 	eup->eu_config.ac_device = DEV_ENI_155P; 	eup->eu_config.ac_media = val& MEDIA_MASK ? MEDIA_UTP155 : MEDIA_OC3C; 	eup->eu_pif.pif_pcr = ATM_PCR_OC3C; 	eup->eu_config.ac_bustype = BUS_PCI; 	eup->eu_config.ac_busslot = config_id->bus<< 8 | config_id->slot;
comment|/* 	 * Make a hw version number from the ID register values. 	 * Format: {Midway ID}.{Mother board ID}.{Daughter board ID} 	 */
end_comment

begin_comment
unit|snprintf ( eup->eu_config.ac_hard_vers, 	    sizeof ( eup->eu_config.ac_hard_vers ), 		"%ld/%ld/%ld", 		(val>> ID_SHIFT)& ID_MASK, 		(val>> MID_SHIFT)& MID_MASK, 		(val>> DID_SHIFT)& DID_MASK );
comment|/* 	 * There is no software version number 	 */
end_comment

begin_comment
unit|eup->eu_config.ac_firm_vers[0] = '\0';
comment|/* 	 * Save device ram info for user-level programs 	 * NOTE: This really points to start of EEPROM 	 * and includes all the device registers in the 	 * lower 2 Megabytes. 	 */
end_comment

begin_comment
unit|eup->eu_config.ac_ram = (long)eup->eu_base; 	eup->eu_config.ac_ramsize = eup->eu_ramsize + ENI_REG_SIZE;
comment|/* 	 * Setup max VPI/VCI values 	 */
end_comment

begin_comment
unit|eup->eu_pif.pif_maxvpi = ENI_MAX_VPI; 	eup->eu_pif.pif_maxvci = ENI_MAX_VCI;
comment|/* 	 * Register this interface with ATM core services 	 */
end_comment

begin_comment
unit|if ( atm_physif_register 		( (Cmn_unit *)eup, ENI_DEV_NAME, eni_services ) != 0 ) 	{
comment|/* 		 * Registration failed - back everything out 		 */
end_comment

begin_if
unit|log(LOG_ERR, "%s%d: atm_physif_register failed\n",  			ENI_DEV_NAME, unit); 		goto failed; 	}  	eni_units[unit] = eup;
if|#
directive|if
name|BSD
operator|>=
literal|199506
end_if

begin_comment
comment|/* 	 * Add hook to out shutdown function 	 */
end_comment

begin_endif
unit|EVENTHANDLER_REGISTER(shutdown_post_sync, eni_pci_shutdown, eup, 			      SHUTDOWN_PRI_DEFAULT);
endif|#
directive|endif
end_endif

begin_comment
comment|/* 	 * Initialize driver processing 	 */
end_comment

begin_comment
unit|if ( eni_init ( eup ) ) { 		log(LOG_ERR, "%s%d: adapter init failed\n",  			ENI_DEV_NAME, unit); 		goto failed; 	}  	return;  failed:
comment|/* 	 * Attach failed - clean up 	 */
end_comment

begin_comment
unit|eni_pci_reset(eup); 	(void) pci_unmap_int(config_id); 	atm_dev_free(eup); 	return; }
comment|/*  * Device reset routine  *  * Arguments:  *	eup			pointer to per unit structure  *  * Returns:  *	none  *  */
end_comment

begin_comment
unit|static void eni_pci_reset ( eup ) 	Eni_unit *eup; {
comment|/* 	 * We should really close down any open VCI's and 	 * release all memory (TX and RX) buffers. For now, 	 * we assume we're shutting the card down for good. 	 */
end_comment

begin_comment
unit|if (eup->eu_midway) {
comment|/* 		 * Issue RESET command to Midway chip 		 */
end_comment

begin_comment
unit|eup->eu_midway[MIDWAY_ID] = MIDWAY_RESET;
comment|/* 		 * Delay to allow everything to terminate 		 */
end_comment

begin_if
unit|DELAY ( MIDWAY_DELAY ); 	}  	return; }
if|#
directive|if
name|BSD
operator|<
literal|199506
end_if

begin_comment
comment|/*  * Device shutdown routine  *  * Arguments:  *	kdc		pointer to device's configuration table  *	force		forced shutdown flag  *  * Returns:  * 	none  *  */
end_comment

begin_comment
unit|static int eni_pci_shutdown ( kdc, force ) 	struct kern_devconf	*kdc; 	int			force; { 	Eni_unit	*eup = NULL;  	if ( kdc->kdc_unit< eni_nunits ) {  		eup = eni_units[kdc->kdc_unit]; 		if ( eup != NULL ) {
comment|/* Do device reset */
end_comment

begin_else
unit|eni_pci_reset ( eup ); 		} 	}  	(void) dev_detach ( kdc ); 	return ( 0 ); }
else|#
directive|else
end_else

begin_comment
comment|/*  * Device shutdown routine  *  * Arguments:  *	howto		type of shutdown  *	eup		pointer to device unit structure  *  * Returns:  *	none  *  */
end_comment

begin_comment
unit|static void eni_pci_shutdown ( eup, howto ) 	void	*eup; 	int	howto; {
comment|/* Do device reset */
end_comment

begin_endif
unit|eni_pci_reset ( eup );  }
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD< 199506 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

