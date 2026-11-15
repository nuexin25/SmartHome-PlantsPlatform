<template>
  <view class="about-bg">
    <view class="about-header">
      <image class="about-logo" src="@/static/Z.jpg" mode="aspectFit" />
      <text class="about-appname">智享家</text>
      <text class="about-version">当前版本：1.0.0</text>
    </view>
    <view class="about-menu">
      <view class="about-menu-item" v-for="item in menuList" :key="item.title" @click="onMenuClick(item)">
        <text>{{ item.title }}</text>
        <text v-if="item.arrow" class="about-arrow">&#8250;</text>
      </view>
    </view>
   
  </view>
</template>

<script>
export default {
  data() {
    return {
      menuList: [
        { title: '公司介绍', arrow: true },
        { title: '版本更新', arrow: true },
        { title: '个人信息收集清单', arrow: true },
      ]
    }
  },
  methods: {
    onMenuClick(item) {
      uni.showToast({ title: item.title, icon: 'none' });
      // 可根据实际需求跳转到对应页面
    }
  }
}
</script>

<style scoped>
.about-bg {
  min-height: 100vh;
  background: #fafbfc;
  display: flex;
  flex-direction: column;
  align-items: center;
  padding-bottom: 40rpx;
}
.about-header {
  margin-top: 80rpx;
  display: flex;
  flex-direction: column;
  align-items: center;
}
.about-logo {
  width: 160rpx;
  height: 160rpx;
  border-radius: 32rpx;
  margin-bottom: 24rpx;
  background: #eaf6ff;
}
.about-appname {
  font-size: 38rpx;
  color: #3a7afe;
  font-weight: bold;
  margin-bottom: 18rpx;
  letter-spacing: 2rpx;
}
.about-version {
  font-size: 28rpx;
  color: #222;
  margin-bottom: 40rpx;
}
.about-menu {
  width: 90vw;
  max-width: 650rpx;
  background: #fff;
  border-radius: 20rpx;
  box-shadow: 0 2rpx 12rpx rgba(0,0,0,0.04);
  margin-bottom: 32rpx;
  overflow: hidden;
}
.about-menu-item {
  display: flex;
  flex-direction: row;
  align-items: center;
  justify-content: space-between;
  height: 90rpx;
  padding: 0 32rpx;
  font-size: 30rpx;
  color: #222;
  border-bottom: 1px solid #f0f0f0;
  background: #fff;
}
.about-menu-item:last-child {
  border-bottom: none;
}
.about-arrow {
  font-size: 38rpx;
  color: #bbb;
}
.about-icp {
  margin-top: 24rpx;
  font-size: 26rpx;
  color: #888;
  text-align: center;
}
.about-icp-num {
  color: #bbb;
}
.about-bottom {
  position: absolute;
  bottom: 24rpx;
  left: 0;
  width: 100vw;
  text-align: center;
  color: #888;
  font-size: 24rpx;
  letter-spacing: 1rpx;
}
</style> 