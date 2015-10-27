#include <linux/module.h>
//#include <linux/init.h>
//#include <linux/uio.h>
//#include <linux/net.h>
//#include <linux/slab.h>
//#include <linux/netdevice.h>
//#include <linux/socket.h>
//#include <linux/if_arp.h>
//#include <linux/skbuff.h>
//#include <linux/inetdevice.h>
#include <net/sock.h>
//#include <net/tcp.h>

//#include <linux/sysctl.h>
//#include <linux/proc_fs.h>
//#include <linux/of.h>

#include "af_test.h"


MODULE_DESCRIPTION("My new network protocol - AF_TEST");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Venkatesh Parthasarathy");

static int af_init(struct sock *sk) {
	return 0;
}

static int af_test_release(struct socket *sock) {
	return 0;
}

static int af_test_bind(struct socket *sock, struct sockaddr *uaddr, int len) {
	return 0;
}

static int af_test_connect(struct socket *sock, struct sockaddr *uaddr, int addr_len, int flags) {
	return 0;
}

static int af_test_accept(struct socket *sock, struct socket *newsock, int flags) {
	return 0;
}

static int af_test_getname(struct socket *sock, struct sockaddr *uaddr, int *len, int peer) {
	return 0;
}

int af_test_ioctl(struct socket *sock, unsigned int cmd, unsigned long arg) {
	return 0;
}

static int af_test_listen(struct socket *sock, int backlog) {
	return 0;
}

static int af_test_shutdown(struct socket *sock, int how) {
	return 0;
}

static int af_test_setsockopt(struct socket *sock, int level, int optname, char __user *optval, unsigned int optlen) {
	return 0;
}

static int af_test_getsockopt(struct socket *sock, int level, int optname, char __user *optval, int __user *optlen) {
	return 0;
}

static int af_test_sendmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg, size_t size) {
	return 0;
}

static int af_test_recvmsg(struct kiocb *iocb, struct socket *sock, struct msghdr *msg, size_t size, int flags) {
	return 0;
}

static int af_test_create(struct net *net, struct socket *sock, int protocol, int kern) {
	return 0;
}

struct proto af_test_proto = {
	.name       = "AF_TEST",
//	.obj_size   = sizeof(struct inc_sock),
	.init = af_init,
	.owner = THIS_MODULE,
};

struct net_proto af_test_net_proto = {
	.name       = PF_TEST,
//	.obj_size   = sizeof(struct inc_sock),
	.create = af_test_create,
	.owner = THIS_MODULE,
};

struct proto_ops af_test_proto_ops = {
	.family = PF_INET,
	.owner = THIS_MODULE,
	.release = af_test_release,
	.bind = af_test_bind,
	.connect = af_test_connect,
	.socketpair = sock_no_socketpair,
	.accept = af_test_accept,
	.getname = af_test_getname,
	.poll = datagram_poll, 
	.ioctl = af_test_ioctl,
	.listen = af_test_listen,
	.shutdown = af_test_shutdown,
	.setsockopt = af_test_setsockopt,
	.getsockopt = af_test_getsockopt,
	.sendmsg = af_test_sendmsg,
	.recvmsg = af_test_recvmsg,
        .mmap          = sock_no_mmap,
        .sendpage      = sock_no_sendpage,
};

static __init int af_test_init(void) {
	printk("TODO init...\n");
	return 0;
}

static __exit int af_test_exit(void) {
	printk("TODO exit...\n");
	return 0;
}

module_init(af_test_init);
module_exit(af_test_exit);
