begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * pppd.h - PPP daemon global declarations.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*  * TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPPD_H__
end_ifndef

begin_define
define|#
directive|define
name|__PPPD_H__
end_define

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_define
define|#
directive|define
name|NPPP
value|1
end_define

begin_comment
comment|/* One PPP interface supported (per process) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debug flag */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ifname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Interface name */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device file descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket descriptor */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hostname */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|hostname_len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* and its length */
end_comment

begin_decl_stmt
specifier|extern
name|u_char
name|outpacket_buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for outgoing packets */
end_comment

begin_define
define|#
directive|define
name|MAX_HOSTNAME_LEN
value|128
end_define

begin_comment
comment|/* should be 255 - MAX_CHALLENGE_LEN + 1 */
end_comment

begin_decl_stmt
name|void
name|quit
name|__ARGS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cleanup and exit */
end_comment

begin_decl_stmt
name|void
name|timeout
name|__ARGS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|caddr_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look-alike of kernel's timeout() */
end_comment

begin_decl_stmt
name|void
name|untimeout
name|__ARGS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look-alike of kernel's untimeout() */
end_comment

begin_decl_stmt
name|void
name|output
name|__ARGS
argument_list|(
operator|(
name|int
operator|,
name|u_char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a PPP packet */
end_comment

begin_decl_stmt
name|void
name|demuxprotrej
name|__ARGS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Demultiplex a Protocol-Reject */
end_comment

begin_decl_stmt
name|u_char
name|login
name|__ARGS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Login user */
end_comment

begin_decl_stmt
name|void
name|logout
name|__ARGS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Logout user */
end_comment

begin_decl_stmt
name|void
name|get_secret
name|__ARGS
argument_list|(
operator|(
name|u_char
operator|*
operator|,
name|u_char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get "secret" for chap */
end_comment

begin_decl_stmt
name|u_long
name|GetMask
name|__ARGS
argument_list|(
operator|(
name|u_long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* get netmask for address */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Inline versions of get/put char/short/long.  * Pointer is advanced; we assume that both arguments  * are lvalues and will already be in registers.  * cp MUST be u_char *.  */
end_comment

begin_define
define|#
directive|define
name|GETCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(c) = *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTCHAR
parameter_list|(
name|c
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (c); \ }
end_define

begin_define
define|#
directive|define
name|GETSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(s) = *(cp)++<< 8; \ 	(s) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTSHORT
parameter_list|(
name|s
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (s)>> 8; \ 	*(cp)++ = (s); \ }
end_define

begin_define
define|#
directive|define
name|GETLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	(l) = *(cp)++<< 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; (l)<<= 8; \ 	(l) |= *(cp)++; \ }
end_define

begin_define
define|#
directive|define
name|PUTLONG
parameter_list|(
name|l
parameter_list|,
name|cp
parameter_list|)
value|{ \ 	*(cp)++ = (l)>> 24; \ 	*(cp)++ = (l)>> 16; \ 	*(cp)++ = (l)>> 8; \ 	*(cp)++ = (l); \ }
end_define

begin_define
define|#
directive|define
name|INCPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) += (n))
end_define

begin_define
define|#
directive|define
name|DECPTR
parameter_list|(
name|n
parameter_list|,
name|cp
parameter_list|)
value|((cp) -= (n))
end_define

begin_comment
comment|/*  * System dependent definitions for user-level 4.3BSD UNIX implementation.  */
end_comment

begin_define
define|#
directive|define
name|DEMUXPROTREJ
parameter_list|(
name|u
parameter_list|,
name|p
parameter_list|)
value|demuxprotrej(u, p)
end_define

begin_define
define|#
directive|define
name|TIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|)
value|timeout((r), (f), (t))
end_define

begin_define
define|#
directive|define
name|UNTIMEOUT
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|untimeout((r), (f))
end_define

begin_define
define|#
directive|define
name|BCOPY
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|,
name|l
parameter_list|)
value|bcopy(s, d, l)
end_define

begin_define
define|#
directive|define
name|EXIT
parameter_list|(
name|u
parameter_list|)
value|quit()
end_define

begin_define
define|#
directive|define
name|GETUSERPASSWD
parameter_list|(
name|u
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOGIN
parameter_list|(
name|n
parameter_list|,
name|u
parameter_list|,
name|ul
parameter_list|,
name|p
parameter_list|,
name|pl
parameter_list|,
name|m
parameter_list|,
name|ml
parameter_list|)
value|login(u, ul, p, pl, m, ml);
end_define

begin_define
define|#
directive|define
name|LOGOUT
parameter_list|(
name|n
parameter_list|)
value|logout()
end_define

begin_define
define|#
directive|define
name|GETSECRET
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|,
name|sl
parameter_list|)
value|get_secret(n, s, sl)
end_define

begin_define
define|#
directive|define
name|PRINTMSG
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|{ m[l] = '\0'; syslog(LOG_INFO, "Remote message: %s", m); }
end_define

begin_comment
comment|/*  * return a pointer to the beginning of the data part of a packet.  */
end_comment

begin_define
define|#
directive|define
name|PACKET_DATA
parameter_list|(
name|p
parameter_list|)
value|(p + DLLHEADERLEN)
end_define

begin_comment
comment|/*  * MAKEHEADER - Add Header fields to a packet.  (Should we do  * AC compression here?)  */
end_comment

begin_define
define|#
directive|define
name|MAKEHEADER
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|{ \     PUTCHAR(ALLSTATIONS, p); \     PUTCHAR(UI, p); \     PUTSHORT(t, p); }
end_define

begin_comment
comment|/*  * SIFASYNCMAP - Config the interface async map.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|SIFASYNCMAP
parameter_list|(
name|u
parameter_list|,
name|a
parameter_list|)
value|{ \      u_long x = a; \      if(ioctl(fd, SIOCSIFASYNCMAP, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFASYNCMAP): %m"); \     } }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIFASYNCMAP
parameter_list|(
name|u
parameter_list|,
name|a
parameter_list|)
value|{ \     u_long x = a; \     if (ioctl(fd, PPPIOCSASYNCMAP, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSASYNCMAP): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFPCOMPRESSION - Config the interface for protocol compression.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|SIFPCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     char c = 1; \     if(ioctl(fd, SIOCSIFCOMPPROT,&c)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFCOMPPROT): %m"); \     }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIFPCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     u_int x; \     if (ioctl(fd, PPPIOCGFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl (PPPIOCGFLAGS): %m"); \ 	quit(); \     } \     x |= SC_COMP_PROT; \     if (ioctl(fd, PPPIOCSFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CIFPCOMPRESSION - Config the interface for no protocol compression.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|CIFPCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     char c = 0; \     if(ioctl(fd, SIOCSIFCOMPPROT,&c)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFCOMPPROT): %m"); \ 	quit(); \     }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CIFPCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     u_int x; \     if (ioctl(fd, PPPIOCGFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCGFLAGS): %m"); \ 	quit(); \     } \     x&= ~SC_COMP_PROT; \     if (ioctl(fd, PPPIOCSFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFACCOMPRESSION - Config the interface for address/control compression.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|SIFACCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \    char c = 1; \     if(ioctl(fd, SIOCSIFCOMPAC,&c)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFCOMPAC): %m"); \ 	quit(); \     }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIFACCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     u_int x; \     if (ioctl(fd, PPPIOCGFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl (PPPIOCGFLAGS): %m"); \ 	quit(); \     } \     x |= SC_COMP_AC; \     if (ioctl(fd, PPPIOCSFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * CIFACCOMPRESSION - Config the interface for no address/control compression.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|CIFACCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     char c = 0; \     if(ioctl(fd, SIOCSIFCOMPAC,&c)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFCOMPAC): %m"); \ 	quit(); \     }}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CIFACCOMPRESSION
parameter_list|(
name|u
parameter_list|)
value|{ \     u_int x; \     if (ioctl(fd, PPPIOCGFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl (PPPIOCGFLAGS): %m"); \ 	quit(); \     } \     x&= ~SC_COMP_AC; \     if (ioctl(fd, PPPIOCSFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFVJCOMP - config tcp header compression  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STREAMS
end_ifdef

begin_define
define|#
directive|define
name|SIFVJCOMP
parameter_list|(
name|u
parameter_list|,
name|a
parameter_list|)
value|{ \     char x = a;			\ 	if (debug) syslog(LOG_DEBUG, "SIFVJCOMP unit %d to value %d\n",u,x); \ 	if(ioctl(fd, SIOCSIFVJCOMP, (caddr_t)&x)< 0) { \ 		syslog(LOG_ERR, "ioctl(SIOCSIFVJCOMP): %m"); \ 		quit(); \ 	} \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIFVJCOMP
parameter_list|(
name|u
parameter_list|,
name|a
parameter_list|)
value|{ \     u_int x; \     if (debug) \ 	syslog(LOG_DEBUG, "PPPIOCSFLAGS unit %d set %s\n",u,a?"on":"off"); \     if (ioctl(fd, PPPIOCGFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl (PPPIOCGFLAGS): %m"); \ 	quit(); \     } \     x = (x& ~SC_COMP_TCP) | ((a) ? SC_COMP_TCP : 0); \     if(ioctl(fd, PPPIOCSFLAGS, (caddr_t)&x)< 0) { \ 	syslog(LOG_ERR, "ioctl(PPPIOCSFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFUP - Config the interface up.  */
end_comment

begin_define
define|#
directive|define
name|SIFUP
parameter_list|(
name|u
parameter_list|)
value|{ \     struct ifreq ifr; \     strncpy(ifr.ifr_name, ifname, sizeof (ifr.ifr_name)); \     if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl (SIOCGIFFLAGS): %m"); \ 	quit(); \     } \     ifr.ifr_flags |= IFF_UP; \     if (ioctl(s, SIOCSIFFLAGS, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_comment
comment|/*  * SIFDOWN - Config the interface down.  */
end_comment

begin_define
define|#
directive|define
name|SIFDOWN
parameter_list|(
name|u
parameter_list|)
value|{ \     struct ifreq ifr; \     strncpy(ifr.ifr_name, ifname, sizeof (ifr.ifr_name)); \     if (ioctl(s, SIOCGIFFLAGS, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl (SIOCGIFFLAGS): %m"); \ 	quit(); \     } \     ifr.ifr_flags&= ~IFF_UP; \     if (ioctl(s, SIOCSIFFLAGS, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFFLAGS): %m"); \ 	quit(); \     } }
end_define

begin_comment
comment|/*  * SIFMTU - Config the interface MTU.  */
end_comment

begin_define
define|#
directive|define
name|SIFMTU
parameter_list|(
name|u
parameter_list|,
name|m
parameter_list|)
value|{ \     struct ifreq ifr; \     strncpy(ifr.ifr_name, ifname, sizeof (ifr.ifr_name)); \     ifr.ifr_mtu = m; \     if (ioctl(s, SIOCSIFMTU, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFMTU): %m"); \ 	quit(); \     } }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__386BSD__
end_ifdef

begin_comment
comment|/* BSD>= 44 ? */
end_comment

begin_define
define|#
directive|define
name|SET_SA_FAMILY
parameter_list|(
name|addr
parameter_list|,
name|family
parameter_list|)
define|\
value|bzero((char *)&(addr), sizeof(addr));	\     addr.sa_family = (family); 			\     addr.sa_len = sizeof(addr);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SET_SA_FAMILY
parameter_list|(
name|addr
parameter_list|,
name|family
parameter_list|)
define|\
value|bzero((char *)&(addr), sizeof(addr));	\     addr.sa_family = (family);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFADDR - Config the interface IP addresses.  */
end_comment

begin_define
define|#
directive|define
name|SIFADDR
parameter_list|(
name|u
parameter_list|,
name|o
parameter_list|,
name|h
parameter_list|)
value|{ \     struct ifreq ifr; \     strncpy(ifr.ifr_name, ifname, sizeof (ifr.ifr_name)); \     SET_SA_FAMILY(ifr.ifr_addr, AF_INET); \     ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr = o; \     if (ioctl(s, SIOCSIFADDR, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFADDR): %m"); \     } \     ((struct sockaddr_in *)&ifr.ifr_dstaddr)->sin_addr.s_addr = h; \     if (ioctl(s, SIOCSIFDSTADDR, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFDSTADDR): %m"); \ 	quit(); \     } }
end_define

begin_comment
comment|/*  * CIFADDR - Clear the interface IP addresses.  */
end_comment

begin_if
if|#
directive|if
name|BSD
operator|>
literal|43
end_if

begin_define
define|#
directive|define
name|CIFADDR
parameter_list|(
name|u
parameter_list|,
name|o
parameter_list|,
name|h
parameter_list|)
value|{ \     struct ortentry rt; \     SET_SA_FAMILY(rt.rt_dst, AF_INET); \     ((struct sockaddr_in *)&rt.rt_dst)->sin_addr.s_addr = h; \     SET_SA_FAMILY(rt.rt_gateway, AF_INET); \     ((struct sockaddr_in *)&rt.rt_gateway)->sin_addr.s_addr = o; \     rt.rt_flags |= RTF_HOST; \     syslog(LOG_INFO, "Deleting host route from %s to %s\n", \ 	   ip_ntoa(h), ip_ntoa(o)); \     if (ioctl(s, SIOCDELRT, (caddr_t)&rt)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCDELRT): %m"); \     } }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CIFADDR
parameter_list|(
name|u
parameter_list|,
name|o
parameter_list|,
name|h
parameter_list|)
value|{ \     struct rtentry rt; \     SET_SA_FAMILY(rt.rt_dst, AF_INET); \     ((struct sockaddr_in *)&rt.rt_dst)->sin_addr.s_addr = h; \     SET_SA_FAMILY(rt.rt_gateway, AF_INET); \     ((struct sockaddr_in *)&rt.rt_gateway)->sin_addr.s_addr = o; \     rt.rt_flags |= RTF_HOST; \     syslog(LOG_INFO, "Deleting host route from %s to %s\n", \ 	   ip_ntoa(h), ip_ntoa(o)); \     if (ioctl(s, SIOCDELRT, (caddr_t)&rt)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCDELRT): %m"); \     } }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SIFMASK - Config the interface net mask  */
end_comment

begin_define
define|#
directive|define
name|SIFMASK
parameter_list|(
name|u
parameter_list|,
name|m
parameter_list|)
value|{ \     struct ifreq ifr; \     strncpy(ifr.ifr_name, ifname, sizeof (ifr.ifr_name)); \     SET_SA_FAMILY(ifr.ifr_addr, AF_INET); \     ((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr.s_addr = m; \     syslog(LOG_INFO, "Setting interface mask to %s\n", ip_ntoa(m)); \     if (ioctl(s, SIOCSIFNETMASK, (caddr_t)&ifr)< 0) { \ 	syslog(LOG_ERR, "ioctl(SIOCSIFADDR): %m"); \     } }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOG_PPP
end_ifndef

begin_comment
comment|/* we use LOG_LOCAL2 for syslog by default */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEBUGMAIN
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGFSM
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUG
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGLCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGIPCP
argument_list|)
operator|||
name|defined
argument_list|(
name|DEBUGUPAP
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|DEBUGCHAP
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_LOCAL2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOG_PPP
value|LOG_DAEMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOG_PPP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGMAIN
end_ifdef

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAINDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGFSM
end_ifdef

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FSMDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGLCP
end_ifdef

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGIPCP
end_ifdef

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IPCPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGUPAP
end_ifdef

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UPAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGCHAP
end_ifdef

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
value|if (debug) syslog x;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHAPDEBUG
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIGTYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|SYSV
argument_list|)
operator|||
name|defined
argument_list|(
name|POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(sun) || defined(SYSV) || defined(POSIX_SOURCE) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIGTYPE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PPP_H__ */
end_comment

end_unit

