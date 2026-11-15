<template>
  <view class="faq-page">
    
    <view class="faq-list">
      <view
        v-for="(item, idx) in faqs"
        :key="idx"
        class="faq-item"
      >
        <view class="faq-q-row" @click="toggle(idx)">
          <text class="faq-q">{{ idx + 1 }}.{{ item.q }}</text>
          <text class="faq-arrow" :class="{ open: openIdx === idx }">&#8744;</text>
        </view>
        <view v-if="openIdx === idx" class="faq-a">
          <text v-for="(line, lidx) in item.a" :key="lidx" class="faq-a-line">{{ line }}</text>
        </view>
      </view>
    </view>
    <view class="faq-suggest-box">
      <textarea
        v-model="suggest"
        maxlength="200"
        class="faq-suggest-input"
        placeholder="请输入您的建议（少于200字）"
        :auto-height="true"
      />
      <view class="faq-suggest-footer">
        <text v-if="!suggest" class="faq-suggest-tip">请少于200字</text>
        <text v-if="showSuccess" class="faq-suggest-success">提交成功</text>
        <button class="faq-suggest-btn" @click="submitSuggest">提交</button>
      </view>
    </view>
  </view>
</template>

<script>
export default {
  data() {
    return {
      openIdx: null,
      suggest: '',
      showSuccess: false,
      faqs: [
        {
          q: '连接不上',
          a: [
            '1) 检查设备和手机是否在同一WiFi网络下。',
            '2) 确认设备已通电并处于可配网状态。',
            '3) 尝试重启设备和手机。',
            '4) 检查App是否有网络权限。'
          ]
        },
        {
          q: '显示未响应',
          a: [
            '1) 检查设备是否断电或离线。',
            '2) 检查路由器是否正常工作。',
            '3) 尝试重新连接设备。',
            '4) 升级设备固件到最新版本。'
          ]
        },
        {
          q: '设备问题',
          a: [
            '1) 检查设备是否有异常指示灯或报警。',
            '2) 参考设备说明书排查常见故障。',
            '3) 尝试恢复出厂设置。',
            '4) 如仍有问题，请联系售后服务。'
          ]
        },
        {
          q: '设备卡死',
          a: [
            '1) 长按电源键重启设备。',
            '2) 断电重启设备。',
            '3) 检查设备是否过热或环境异常。',
            '4) 如多次卡死，请联系售后更换或维修。'
          ]
        }
      ]
    }
  },
  methods: {
    toggle(idx) {
      this.openIdx = this.openIdx === idx ? null : idx;
    },
    submitSuggest() {
      if (!this.suggest || this.suggest.length > 200) return;
      this.showSuccess = true;
      setTimeout(() => {
        this.showSuccess = false;
        this.suggest = '';
      }, 1500);
    }
  }
}
</script>

<style scoped>
.faq-page {
  background: #f7f7f7;
  min-height: 100vh;
  padding-bottom: 32rpx;
}
.faq-header {
  padding-top: 48rpx;
  padding-bottom: 24rpx;
  background: #fff;
  text-align: center;
}
.faq-title {
  font-size: 36rpx;
  font-weight: bold;
  color: #222;
}
.faq-list {
  padding: 0 0 0 0;
}
.faq-item {
  background: #fff;
  border-radius: 16rpx;
  margin: 24rpx 24rpx 0 24rpx;
  box-shadow: 0 2rpx 12rpx rgba(0,0,0,0.04);
  overflow: hidden;
}
.faq-q-row {
  display: flex;
  align-items: center;
  justify-content: space-between;
  padding: 32rpx 32rpx 32rpx 32rpx;
}
.faq-q {
  font-size: 30rpx;
  color: #222;
  font-weight: 500;
}
.faq-arrow {
  font-size: 36rpx;
  color: #bbb;
  transition: transform 0.2s;
}
.faq-arrow.open {
  transform: rotate(180deg);
}
.faq-a {
  padding: 0 32rpx 32rpx 32rpx;
}
.faq-a-line {
  display: block;
  font-size: 26rpx;
  color: #888;
  line-height: 1.8;
  margin-top: 8rpx;
}
.faq-suggest-box {
  background: linear-gradient(135deg, #fafdff 60%, #e9f3ff 100%);
  border-radius: 20rpx;
  margin: 40rpx 12rpx 0 12rpx;
  box-shadow: 0 4rpx 24rpx rgba(52,120,246,0.06);
  padding: 24rpx 12rpx 16rpx 12rpx;
  display: flex;
  flex-direction: column;
  border: 1.5rpx solid #e3eaf2;
  max-width: 100vw;
  box-sizing: border-box;
}
.faq-suggest-input {
  width: 100%;
  min-height: 80rpx;
  font-size: 28rpx;
  color: #222;
  background: #f7faff;
  border-radius: 14rpx;
  padding: 14rpx 12rpx;
  border: 1.5rpx solid #dbeafe;
  margin-bottom: 12rpx;
  box-shadow: 0 2rpx 8rpx rgba(52,120,246,0.04);
  outline: none;
  resize: none;
  box-sizing: border-box;
}
.faq-suggest-footer {
  display: flex;
  align-items: center;
  justify-content: space-between;
  flex-wrap: wrap;
}
.faq-suggest-tip {
  color: #f56c6c;
  font-size: 24rpx;
}
.faq-suggest-success {
  color: #67c23a;
  font-size: 24rpx;
}
.faq-suggest-btn {
  background: linear-gradient(90deg, #3478f6 60%, #5eaefd 100%);
  color: #fff;
  font-size: 28rpx;
  border: none;
  border-radius: 24rpx;
  padding: 12rpx 40rpx;
  margin-left: 16rpx;
  box-shadow: 0 2rpx 8rpx rgba(52,120,246,0.10);
  transition: background 0.2s;
  white-space: nowrap;
}
.faq-suggest-btn:active {
  background: linear-gradient(90deg, #2a5ebc 60%, #4b8ed6 100%);
}
</style> 