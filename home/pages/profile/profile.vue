<template>
	<view class="profile-bg">
		<!-- 顶部白色导航栏 -->
		<view class="card profile-card" @click="handleProfileCardClick">
			<view class="profile-info">
				<view class="profile-avatar" @click.stop="handleAvatarClick">
					<image v-if="userInfo && userInfo.avatar" :src="userInfo.avatar" class="avatar-img"/>
					<svg v-else width="100" height="100" viewBox="0 0 48 48">
						<circle cx="24" cy="24" r="24" fill="#f0f0f0"/>
						<path d="M24 26c-4.5 0-8 3.5-8 8h16c0-4.5-3.5-8-8-8zm0-2c2.7 0 5-2.3 5-5s-2.3-5-5-5-5 2.3-5 5 2.3 5 5 5z" fill="#ccc"/>
					</svg>
				</view>
				<text class="profile-name" :class="{ 'logged-in': currentUser, 'not-logged': !currentUser }">
					{{ currentUser ? '欢迎，' + currentUser : '未登录' }}
				</text>
				<text class="profile-arrow-right">&gt;</text>
				<!-- 可扩展显示更多信息 -->
				<view v-if="userInfo && currentUser" class="profile-extra">
					<!-- 例如：<text>手机号：{{ userInfo.phone }}</text> -->
				</view>
			</view>
		</view>
		<view class="card menu-card">
			<view class="menu-item" v-for="(item, idx) in menuList" :key="item.title" @click="goTo(item.type)">
				<view class="menu-icon" v-html="item.icon"></view>
				<text class="menu-title">{{ item.title }}</text>
				<view class="menu-arrow">
					<svg width="18" height="18" viewBox="0 0 24 24"><path d="M9 6l6 6-6 6" fill="none" stroke="#d1d5db" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"/></svg>
				</view>
			</view>
		</view>
		<button v-if="currentUser" class="logout-btn" @click="logout">退出登录</button>
	</view>
</template>

<script>
const icons = {
	health: `<svg width="26" height="26" viewBox="0 0 24 24"><path d="M12 21c-4.97-4.97-8-7.99-8-11.5A5.5 5.5 0 0112 4a5.5 5.5 0 018 5.5c0 3.51-3.03 6.53-8 11.5z" fill="none" stroke="#8c939a" stroke-width="2"/><path d="M12 8v4" stroke="#8c939a" stroke-width="2" stroke-linecap="round"/><circle cx="12" cy="16" r="1" fill="#8c939a"/></svg>`,
	location: `<svg width="26" height="26" viewBox="0 0 24 24"><circle cx="12" cy="10" r="3" fill="none" stroke="#8c939a" stroke-width="2"/><path d="M12 2C7 2 3 6.03 3 11c0 5.25 7.5 11 9 11s9-5.75 9-11c0-4.97-4-9-9-9z" fill="none" stroke="#8c939a" stroke-width="2"/></svg>`,
	support: `<svg width="26" height="26" viewBox="0 0 24 24"><rect x="4" y="7" width="16" height="10" rx="2" fill="none" stroke="#8c939a" stroke-width="2"/><path d="M8 17v2m8-2v2" stroke="#8c939a" stroke-width="2" stroke-linecap="round"/></svg>`,
	pair: `<svg width="26" height="26" viewBox="0 0 24 24"><path d="M7 7l10 10M7 17L17 7" fill="none" stroke="#8c939a" stroke-width="2"/><circle cx="12" cy="12" r="10" fill="none" stroke="#8c939a" stroke-width="2"/></svg>`,
	widget: `<svg width="26" height="26" viewBox="0 0 24 24"><rect x="3" y="3" width="7" height="7" rx="2" fill="none" stroke="#8c939a" stroke-width="2"/><rect x="14" y="3" width="7" height="7" rx="2" fill="none" stroke="#8c939a" stroke-width="2"/><rect x="14" y="14" width="7" height="7" rx="2" fill="none" stroke="#8c939a" stroke-width="2"/><rect x="3" y="14" width="7" height="7" rx="2" fill="none" stroke="#8c939a" stroke-width="2"/></svg>`,
	faq: `<svg width="26" height="26" viewBox="0 0 24 24"><circle cx="12" cy="12" r="10" fill="none" stroke="#8c939a" stroke-width="2"/><path d="M12 16v-2m0-4a2 2 0 012 2c0 1-2 1-2 3" fill="none" stroke="#8c939a" stroke-width="2" stroke-linecap="round"/></svg>`,
	about: `<svg width="26" height="26" viewBox="0 0 24 24"><circle cx="12" cy="12" r="10" fill="none" stroke="#8c939a" stroke-width="2"/><path d="M12 8v4m0 4h.01" fill="none" stroke="#8c939a" stroke-width="2" stroke-linecap="round"/></svg>`
}
export default {
	data() {
		return {
			menuList: [
				{ title: '使用说明', type: 'widget', icon: icons.widget },
				{ title: '常见问题', type: 'faq', icon: icons.faq },
				{ title: '关于我们', type: 'about', icon: icons.about },
			],
			currentUser: '',
			userInfo: null,
			username: '',
			password: ''
		}
	},
	onShow() {
		this.currentUser = uni.getStorageSync('currentUser') || '';
		if (this.currentUser) {
			const users = uni.getStorageSync('users') || {};
			this.userInfo = users[this.currentUser] || null;
		} else {
			this.userInfo = null;
		}
	},
	methods: {
		handleProfileCardClick() {
			if (!this.currentUser) {
				uni.navigateTo({ url: '/pages/login/login' });
			}
		},
		goTo(type) {
			if (type === 'faq') {
				uni.navigateTo({ url: '/pages/faq/faq' });
				return;
			}
			if (type === 'widget') {
				uni.navigateTo({ url: '/pages/guide/guide' });
				return;
			}
			if (type === 'about') {
				uni.navigateTo({ url: '/pages/about/about' });
				return;
			}
			uni.showToast({ title: '点击了' + type, icon: 'none' })
		},
		login() {
			if (!this.username || !this.password) {
				uni.showToast({ title: '请输入账号和密码', icon: 'none' });
				return;
			}
			let users = uni.getStorageSync('users') || {};
			if (!users[this.username] || users[this.username].password !== this.password) {
				uni.showToast({ title: '账号或密码错误', icon: 'none' });
				return;
			}
			// 登录成功，保存当前用户
			uni.setStorageSync('currentUser', this.username);
			uni.showToast({ title: '登录成功', icon: 'success' });
			setTimeout(() => {
				uni.switchTab({ url: '/pages/profile/profile' });
			}, 800);
		},
		register() {
			if (!this.username || !this.password) {
				uni.showToast({ title: '请输入账号和密码', icon: 'none' });
				return;
			}
			let users = uni.getStorageSync('users') || {};
			if (users[this.username]) {
				uni.showToast({ title: '用户名已存在', icon: 'none' });
				return;
			}
			// 可扩展更多信息
			users[this.username] = { password: this.password };
			uni.setStorageSync('users', users);
			uni.showToast({ title: '注册成功，请登录', icon: 'success' });
		},
		logout() {
			uni.removeStorageSync('currentUser');
			this.currentUser = '';
			this.userInfo = null;
			uni.showToast({ title: '已退出登录' });
		},
		async handleAvatarClick() {
			if (!this.currentUser) {
				uni.navigateTo({ url: '/pages/login/login' });
				return;
			}
			const res = await uni.chooseImage({ count: 1, sizeType: ['compressed'] });
			if (res.tempFilePaths && res.tempFilePaths.length > 0) {
				const avatarPath = res.tempFilePaths[0];
				let users = uni.getStorageSync('users') || {};
				if (!users[this.currentUser]) return;
				users[this.currentUser].avatar = avatarPath;
				uni.setStorageSync('users', users);
				this.userInfo.avatar = avatarPath;
				uni.showToast({ title: '头像已更新' });
			}
		}
	}
}
</script>

<style scoped>
	.profile-bg {
		min-height: 100vh;
		background: #f5f6f8;
		padding: 0;
		display: flex;
		flex-direction: column;
		align-items: center;
	}
	.nav-bar {
		width: 100vw;
		height: 96rpx;
		background: #fff;
		display: flex;
		align-items: flex-end;
		justify-content: center;
		box-sizing: border-box;
		padding-bottom: 12rpx;
		font-weight: bold;
		font-size: 34rpx;
		color: #222;
		letter-spacing: 2rpx;
		box-shadow: 0 2rpx 8rpx rgba(0,0,0,0.01);
	}
	.nav-title {
		font-size: 34rpx;
		color: #222;
		font-weight: bold;
	}
	.card {
		width: 85vw;
		max-width: 600rpx;
		background: #fff;
		border-radius: 24rpx;
		box-shadow: 0 4rpx 24rpx rgba(0,0,0,0.06);
		margin-bottom: 32rpx;
		padding: 0;
		position: relative;
		overflow: hidden;
	}
	.profile-card {
		margin-top: 32rpx;
		padding: 0;
		height: 200rpx;
		display: flex;
		align-items: center;
	}
	.profile-info {
		display: flex;
		flex-direction: row;
		align-items: center;
		height: 200rpx;
		padding: 0 40rpx;
		width: 100%;
	}
	.profile-avatar {
		width: 100rpx;
		height: 100rpx;
		border-radius: 50%;
		background: #f0f0f0;
		display: flex;
		align-items: center;
		justify-content: center;
		margin-right: 32rpx;
		cursor: pointer;
	}
	.avatar-img {
		width: 100rpx;
		height: 100rpx;
		border-radius: 50%;
		object-fit: cover;
	}
	.profile-name {
		font-size: 36rpx;
		flex: 2;
		min-width: 200rpx;
		color: #888;
		font-weight: normal;
	}
	.profile-name.logged-in {
		color: #2563eb;
		font-weight: bold;
		font-size: 40rpx;
	}
	.profile-name.not-logged {
		color: #888;
		font-weight: normal;
	}
	.profile-arrow {
		margin-left: 8rpx;
		display: flex;
		align-items: center;
	}
	.profile-arrow-right {
		margin-left: 12rpx;
		font-size: 32rpx;
		color: #bbb;
		font-weight: bold;
	}
	.menu-card {
		padding: 0;
	}
	.menu-item {
		display: flex;
		flex-direction: row;
		align-items: center;
		padding: 0 24rpx;
		height: 88rpx;
		border-bottom: 1px solid #f0f0f0;
		background: #fff;
	}
	.menu-item:last-child {
		border-bottom: none;
	}
	.menu-icon {
		width: 38rpx;
		display: flex;
		align-items: center;
		justify-content: center;
		margin-right: 18rpx;
	}
	.menu-title {
		font-size: 28rpx;
		color: #222;
		flex: 2;
		min-width: 120rpx;
	}
	.menu-arrow {
		display: flex;
		align-items: center;
		color: #bbb;
		font-size: 32rpx;
		margin-left: 8rpx;
	}
	.logout-btn {
		margin: 32rpx auto 0 auto;
		width: 60vw;
		max-width: 320px;
		height: 80rpx;
		background: linear-gradient(90deg, #3478f6, #5eaefd);
		color: #fff;
		border: none;
		border-radius: 16rpx;
		font-size: 30rpx;
		display: block;
		box-shadow: 0 2rpx 8rpx rgba(52,120,246,0.08);
	}
</style> 