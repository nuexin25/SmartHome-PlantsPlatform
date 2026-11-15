<template>
  <view class="login-bg">
    <view class="login-card">
      <view class="logo-box">
        <image src="/static/Z.jpg" class="join-logo" mode="aspectFit" />
        <text class="app-title">智享家</text>
      </view>
      <view class="login-header">
        <text class="login-title">欢迎回来</text>
        <text class="login-subtitle">登录您的智能家居账号</text>
      </view>
      
      <view class="input-group">
        <view class="input-item">
          <text class="input-label">用户名</text>
          <input 
            v-model="username" 
            placeholder="请输入用户名" 
            class="login-input" 
          />
        </view>
        
        <view class="input-item">
          <text class="input-label">密码</text>
          <input 
            v-model="password" 
            type="password" 
            placeholder="请输入密码" 
            class="login-input" 
          />
        </view>
      </view>

      <button class="login-btn" @click="handleLogin">登录</button>
      
      <view class="register-link">
        <text>还没有账号？</text>
        <text class="link" @click="goToRegister">立即注册</text>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  data() {
    return {
      username: '',
      password: ''
    }
  },
  methods: {
    handleLogin() {
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
      uni.showToast({ 
        title: '登录成功', 
        icon: 'success',
        duration: 2000
      });
      
      setTimeout(() => {
        uni.switchTab({ url: '/pages/profile/profile' });
      }, 2000);
    },
    
    goToRegister() {
      uni.navigateTo({ url: '/pages/login/register' });
    }
  }
}
</script>

<style scoped>
.login-bg {
  min-height: 100vh;
  background: #fff;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 40rpx;
}

.login-card {
  width: 100%;
  max-width: 600rpx;
  background: #fff;
  border-radius: 24rpx;
  box-shadow: 0 8rpx 32rpx rgba(0,0,0,0.08);
  padding: 48rpx 40rpx;
}

.logo-box {
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-bottom: 24rpx;
}
.join-logo {
  width: 96rpx;
  height: 96rpx;
  border-radius: 24rpx;
  margin-bottom: 8rpx;
  box-shadow: 0 4rpx 16rpx rgba(0,0,0,0.08);
}
.app-title {
  font-size: 36rpx;
  color: #222;
  font-weight: 700;
  letter-spacing: 4rpx;
  margin-bottom: 8rpx;
}

.login-header {
  text-align: center;
  margin-bottom: 48rpx;
}

.login-title {
  font-size: 40rpx;
  color: #111;
  font-weight: bold;
  margin-bottom: 12rpx;
  display: block;
}

.login-subtitle {
  font-size: 28rpx;
  color: #888;
  display: block;
}

.input-group {
  margin-bottom: 40rpx;
  width: 100%;
  box-sizing: border-box;
}

.input-item {
  margin-bottom: 24rpx;
  width: 100%;
  box-sizing: border-box;
}

.input-label {
  font-size: 28rpx;
  color: #222;
  margin-bottom: 8rpx;
  display: block;
}

.login-input {
  width: 100%;
  height: 88rpx;
  background: #fafafa;
  border: 2rpx solid #222;
  border-radius: 12rpx;
  padding: 0 24rpx;
  font-size: 28rpx;
  color: #111;
  transition: all 0.3s;
  box-sizing: border-box;
}

.login-input:focus {
  border-color: #111;
  background: #fff;
}

.login-btn {
  width: 100%;
  height: 88rpx;
  background: #111;
  color: #fff;
  font-size: 32rpx;
  font-weight: 500;
  border-radius: 12rpx;
  margin-bottom: 32rpx;
  border: none;
}

.login-btn:active {
  opacity: 0.9;
}

.register-link {
  text-align: center;
  font-size: 28rpx;
  color: #888;
}

.link {
  color: #111;
  margin-left: 8rpx;
}
</style> 