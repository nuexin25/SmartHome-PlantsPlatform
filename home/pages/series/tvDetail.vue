<template>
  <view class="door-detail-bg">
    <view class="door-detail-card">
      <image class="detail-img" src="/static/ds2.jpg" mode="aspectFit" />
      <view class="detail-section">
        <text class="detail-title">D1 智能电视</text>
        <text class="detail-model">型号：D1</text>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">产品特点</text>
        <view class="detail-list">
          <text class="detail-list-item">4K超高清画质，色彩鲜明</text>
          <text class="detail-list-item">智能语音遥控，操作便捷</text>
          <text class="detail-list-item">多平台内容，丰富娱乐</text>
        </view>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">使用说明</text>
        <view class="detail-list">
          <text class="detail-list-item">1. 按说明书正确安装底座或挂墙</text>
          <text class="detail-list-item">2. 连接WiFi，登录账号</text>
          <text class="detail-list-item">3. 使用语音遥控器进行操作</text>
        </view>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">整体介绍</text>
        <text class="detail-content">
          D1系列智能电视拥有4K超高清画质，支持智能语音操控，内容丰富，满足家庭多样化娱乐需求。
        </text>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  name: 'TvDetail'
}
</script>

<style scoped>
.door-detail-bg {
  min-height: 100vh;
  background: #f5f6f8;
  display: flex;
  flex-direction: column;
  align-items: center;
  padding: 0;
}
.door-detail-card {
  width: 92vw;
  max-width: 700rpx;
  background: #fff;
  border-radius: 28rpx;
  margin: 32rpx 0 0 0;
  box-shadow: 0 8rpx 32rpx rgba(0,0,0,0.10);
  padding-bottom: 32rpx;
  overflow: hidden;
}
.detail-img {
  width: 100%;
  max-width: 500rpx;
  height: 260rpx;
  display: block;
  margin: 24rpx auto 32rpx auto;
  border-radius: 16rpx;
  background: #fff;
}
.detail-section {
  margin: 0 32rpx 28rpx 32rpx;
  padding: 0;
}
.detail-title {
  font-size: 40rpx;
  font-weight: bold;
  color: #222;
  margin-top: 28rpx;
  margin-bottom: 8rpx;
  display: block;
  letter-spacing: 2rpx;
}
.detail-model {
  font-size: 28rpx;
  color: #2563eb;
  font-weight: 500;
  margin-bottom: 8rpx;
  display: block;
}
.detail-subtitle {
  font-size: 30rpx;
  color: #2563eb;
  font-weight: 600;
  margin-bottom: 12rpx;
  display: block;
}
.detail-list {
  display: flex;
  flex-direction: column;
  gap: 8rpx;
}
.detail-list-item {
  font-size: 28rpx;
  color: #444;
  background: #f5f6f8;
  border-radius: 12rpx;
  padding: 12rpx 20rpx;
  margin-bottom: 0;
}
.detail-content {
  font-size: 28rpx;
  color: #444;
  line-height: 1.7;
  display: block;
  margin-top: 4rpx;
  background: #f5f6f8;
  border-radius: 12rpx;
  padding: 18rpx 20rpx;
}
</style> 