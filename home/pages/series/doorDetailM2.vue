<template>
  <view class="door-detail-bg">
    <view class="door-detail-card">
      <image class="detail-img" src="/static/M3.png" mode="aspectFit" />
      <view class="detail-section">
        <text class="detail-title">M2 智能安全门</text>
        <text class="detail-model">型号：M2</text>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">产品特点</text>
        <view class="detail-list">
          <text class="detail-list-item">高强度合金，防腐耐用</text>
          <text class="detail-list-item">多重安全锁，守护家庭</text>
          <text class="detail-list-item">时尚外观，百搭家装</text>
        </view>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">使用说明</text>
        <view class="detail-list">
          <text class="detail-list-item">1. 按说明书安装门体和锁具</text>
          <text class="detail-list-item">2. 设置门锁密码或指纹</text>
          <text class="detail-list-item">3. 定期维护门锁，确保安全</text>
        </view>
      </view>
      <view class="detail-section">
        <text class="detail-subtitle">整体介绍</text>
        <text class="detail-content">
          M2系列门采用高强度合金材料，结合多重安全锁设计，提升家庭安全防护等级。外观时尚，适合多种装修风格。
        </text>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  name: 'DoorDetailM2'
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