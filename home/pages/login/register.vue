<template>
  <view class="register-bg">
    <view class="register-card">
      <view class="logo-box">
        <image src="/static/Z.jpg" class="join-logo" mode="aspectFit" />
        <text class="app-title">智享家</text>
      </view>
      <view class="register-header">
        <text class="register-title">创建账号</text>
        <text class="register-subtitle">欢迎加入智能家居大家庭</text>
      </view>
      
      <view class="input-group">
        <view class="input-item">
          <text class="input-label">手机号</text>
          <input 
            v-model="phone" 
            type="number" 
            maxlength="11"
            placeholder="请输入手机号" 
            class="register-input" 
          />
        </view>
        
        <view class="input-item">
          <text class="input-label">用户名</text>
          <input 
            v-model="username" 
            placeholder="请设置用户名" 
            class="register-input" 
          />
        </view>
        
        <view class="input-item">
          <text class="input-label">密码</text>
          <input 
            v-model="password" 
            type="password" 
            placeholder="请设置密码" 
            class="register-input" 
          />
        </view>
        
        <view class="input-item">
          <text class="input-label">确认密码</text>
          <input 
            v-model="confirmPassword" 
            type="password" 
            placeholder="请再次输入密码" 
            class="register-input" 
          />
        </view>
      </view>

      <button class="register-btn" @click="handleRegister">注册</button>
      
      <view class="login-link">
        <text>已有账号？</text>
        <text class="link" @click="goToLogin">立即登录</text>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  data() {
    return {
      phone: '',
      username: '',
      password: '',
      confirmPassword: ''
    }
  },
  methods: {
    handleRegister() {
      // 表单验证
      if (!this.phone || !this.username || !this.password || !this.confirmPassword) {
        uni.showToast({ title: '请填写完整信息', icon: 'none' });
        return;
      }
      
      if (!/^1[3-9]\d{9}$/.test(this.phone)) {
        uni.showToast({ title: '请输入正确的手机号', icon: 'none' });
        return;
      }
      
      if (this.password !== this.confirmPassword) {
        uni.showToast({ title: '两次输入的密码不一致', icon: 'none' });
        return;
      }
      
      // 检查用户名是否已存在
      let users = uni.getStorageSync('users') || {};
      if (users[this.username]) {
        uni.showToast({ title: '用户名已存在', icon: 'none' });
        return;
      }
      
      // 注册成功
      users[this.username] = {
        phone: this.phone,
        password: this.password
      };
      uni.setStorageSync('users', users);
      
      uni.showToast({ 
        title: '注册成功', 
        icon: 'success',
        duration: 2000
      });
      
      // 延迟跳转到登录页
      setTimeout(() => {
        uni.navigateBack();
      }, 2000);
    },
    
    goToLogin() {
      uni.navigateBack();
    }
  }
}
</script>

<style scoped>
.register-bg {
  min-height: 100vh;
  background: #fff;
  display: flex;
  align-items: center;
  justify-content: center;
  padding: 40rpx;
}

.register-card {
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

.register-header {
  text-align: center;
  margin-bottom: 48rpx;
}

.register-title {
  font-size: 40rpx;
  color: #111;
  font-weight: bold;
  margin-bottom: 12rpx;
  display: block;
}

.register-subtitle {
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

.register-input {
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

.register-input:focus {
  border-color: #111;
  background: #fff;
}

.register-btn {
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

.register-btn:active {
  opacity: 0.9;
}

.login-link {
  text-align: center;
  font-size: 28rpx;
  color: #888;
}

.link {
  color: #111;
  margin-left: 8rpx;
}
</style> 