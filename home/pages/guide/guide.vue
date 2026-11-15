<template>
  <view class="guide-page">
    <view class="guide-steps">
      <view class="guide-step">
        <view class="guide-step-num">1</view>
        <view class="guide-step-content">
          点击设置
          <image class="guide-step-img" src="@/static/A1.jpg" mode="widthFix" />
        </view>
      </view>
      <view class="guide-step">
        <view class="guide-step-num">2</view>
        <view class="guide-step-content">
          打开热点，将热点账号改为 <text class="guide-highlight">ZhiXiang</text>密码改为 <text class="guide-highlight">zx123456</text>
		  频段改为 <text class="guide-highlight">2.4GHz</text>
          <text class="guide-tip">（需修改请联系客服）</text>
          <image class="guide-step-img" src="@/static/A2.jpg" mode="widthFix" />
        </view>
      </view>
      <view class="guide-step">
        <view class="guide-step-num">3</view>
        <view class="guide-step-content">设备上电按下开关</view>
      </view>
      <view class="guide-step">
        <view class="guide-step-num">4</view>
        <view class="guide-step-content">
          设备上线
          <image class="guide-step-img" src="@/static/A4.jpg" mode="widthFix" />
        </view>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  name: 'GuidePage'
}
</script>

<style scoped>
.guide-page {
  min-height: 100vh;
  background: #fff;
  padding: 0 0 32rpx 0;
  display: flex;
  flex-direction: column;
  align-items: center;
}
.guide-steps {
  margin: 64rpx 0 0 0;
  width: 92vw;
  max-width: 600rpx;
  background: #fff;
  border-radius: 20rpx;
  box-shadow: 0 2rpx 12rpx rgba(52,120,246,0.06);
  padding: 32rpx 0 32rpx 0;
}
.guide-step {
  display: flex;
  flex-direction: row;
  align-items: flex-start;
  margin-bottom: 36rpx;
  padding: 0 32rpx;
}
.guide-step:last-child {
  margin-bottom: 0;
}
.guide-step-num {
  width: 44rpx;
  height: 44rpx;
  background: linear-gradient(135deg, #3478f6 60%, #5eaefd 100%);
  color: #fff;
  font-size: 26rpx;
  font-weight: bold;
  border-radius: 50%;
  display: flex;
  align-items: center;
  justify-content: center;
  margin-right: 22rpx;
  box-shadow: 0 2rpx 8rpx rgba(52,120,246,0.13);
  flex-shrink: 0;
}
.guide-step-content {
  font-size: 28rpx;
  color: #222;
  line-height: 1.8;
  word-break: break-all;
  display: flex;
  flex-direction: column;
  flex: 1;
  align-items: flex-start;
}
.guide-step-img {
  width: 80%;
  max-width: 320px;
  margin: 24rpx auto 0 auto;
  display: block;
  border-radius: 12rpx;
  box-shadow: 0 2rpx 8rpx rgba(52,120,246,0.06);
}
.guide-highlight {
  color: #2563eb;
  font-weight: bold;
  font-size: 30rpx;
  margin: 0 4rpx;
}
.guide-tip {
  color: #f56c6c;
  font-size: 24rpx;
  margin-left: 8rpx;
}
</style> 